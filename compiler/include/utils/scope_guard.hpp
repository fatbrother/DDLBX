#pragma once

#include <utility>

template <typename FunctionType>
class ScopeGuard
{
public:
    void dismiss() { dismissed_ = true; }
    explicit ScopeGuard(FunctionType &fn) : function_(std::as_const(fn)) {}
    explicit ScopeGuard(const FunctionType &fn) : function_(fn) {}
    explicit ScopeGuard(FunctionType &&fn) : function_(std::move(fn)) {}

    ScopeGuard(ScopeGuard &&other) : function_(std::move(other.function_)) {}

    ~ScopeGuard() {
        if (!dismissed_) {
            function_();
        }
    }

private:
    bool dismissed_ = false;
    FunctionType function_;
};

template <typename F>
ScopeGuard<std::decay_t<F>> makeGuard(F &&f)
{
    return ScopeGuard<std::decay_t<F>>(std::forward<F>(f));
}
