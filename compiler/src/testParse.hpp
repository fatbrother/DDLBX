#include<tao/pegtl.hpp>

namespace pegtl = tao::pegtl;

namespace testParse {
    namespace grammer{
        struct prefix : pegtl::string< 'H', 'e', 'l', 'l', 'o', ',', ' ' > {};
        struct name : pegtl::plus< pegtl::alpha > {};
        struct gra : pegtl::seq< prefix, name, pegtl::one< '!' >, pegtl::eof > {};
    } 
    template< typename Rule >
    struct action
    {};

    template<>
    struct action< grammer::name >
    {
        template< typename ActionInput >
        static void apply( const ActionInput& in, std::string& v )
        {
            v = in.string();
        }
    };
}// namespace testParse