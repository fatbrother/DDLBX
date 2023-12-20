#include<tao/pegtl.hpp>

namespace pegtl = tao::pegtl;

namespace ddlbx {
namespace grammer {

    //Space----------------------------------------------------
    struct Space : pegtl::star<
        pegtl::one<' '>
    > {};
    //Space----------------------------------------------------

    //End------------------------------------------------------
    struct End : pegtl::one<'!'> {};
    //End------------------------------------------------------

    //basic----------------------------------------------------
    struct Letter : pegtl::sor< 
        pegtl::range<'a', 'z'>,
        pegtl::range<'A', 'Z'>
    > {};
    
    struct Digit : pegtl::range<'0', '9'> {};

    struct Symbol : pegtl::sor<
        pegtl::one<'!'>,
        pegtl::one<'@'>,
        pegtl::one<'#'>,
        pegtl::one<'$'>,
        pegtl::one<'%'>,
        pegtl::one<'^'>,
        pegtl::one<'&'>,
        pegtl::one<'*'>,
        pegtl::one<'('>,
        pegtl::one<')'>,
        pegtl::one<'-'>,
        pegtl::one<'+'>,
        pegtl::one<'='>,
        pegtl::one<'{'>,
        pegtl::one<'}'>,
        pegtl::one<'['>,
        pegtl::one<']'>,
        pegtl::one<'|'>,
        pegtl::one<'\\'>,
        pegtl::one<':'>,
        pegtl::one<';'>,
        pegtl::one<'\''>,
        pegtl::one<'"'>,
        pegtl::one<'<'>,
        pegtl::one<'>'>,
        pegtl::one<','>,
        pegtl::one<'.'>,
        pegtl::one<'?'>,
        pegtl::one<'/'>,
        pegtl::one<'`'>,
        pegtl::one<'~'>,
        pegtl::one<'_'>
    > {};

    struct Operator : pegtl::sor<
        pegtl::string<'+'>,
        pegtl::string<'-'>,
        pegtl::string<'*'>,
        pegtl::string<'/'>,
        pegtl::string<'%'>,
        pegtl::string<'+', '='>,
        pegtl::string<'-', '='>,
        pegtl::string<'*', '='>,
        pegtl::string<'/', '='>,
        pegtl::string<'=', '='>,
        pegtl::string<'%', '='>,
        pegtl::string<'<'>,
        pegtl::string<'>'>,
        pegtl::string<'<', '='>,
        pegtl::string<'>', '='>,
        pegtl::string<'&', '&'>,
        pegtl::string<'|', '|'>,
        pegtl::string<'='>
    > {};


    struct Character : pegtl::sor<
        Letter,
        Digit,
        Symbol
    > {};

    //basic----------------------------------------------------

    //variable-------------------------------------------------

    struct Identifier : pegtl::plus<
        pegtl::sor<
            Letter,
            Digit,
            pegtl::one<'_'>
        >
    > {};

    struct Number : pegtl::seq<
        pegtl::opt<
            pegtl::one<'-'>
        >,
        pegtl::plus<Digit>,
        pegtl::opt<
            pegtl::seq<
                pegtl::one<'.'>,
                pegtl::plus<Digit>
            >
        >
    > {};

    struct String : pegtl::seq<
        pegtl::one<'\''>,
        pegtl::star<Character>,
        pegtl::one<'\''>
    > {};  

    struct Boolean : pegtl::sor<
        pegtl::string<'t', 'r', 'u', 'e'>,
        pegtl::string<'f', 'a', 'l', 's', 'e'>
    > {};

    struct Literal;
    struct List;

    struct Literal : pegtl::sor<
        Number,
        String,
        Boolean,
        List
    > {};

    struct List : pegtl::seq<
        pegtl::one<'['>,
        Literal,
        pegtl::star<
            pegtl::seq<
                pegtl::one<','>,
                Literal
            >
        >,
        pegtl::one<']'>
    > {};

    struct Regex : pegtl::seq<
        pegtl::one<'@'>,
        pegtl::one<'('>,
        pegtl::star<Character>,
        pegtl::one<')'>
    > {};

    struct Type : pegtl::sor<
        pegtl::string<'I', 'n', 't'>,
        pegtl::string<'S', 't', 'r'>,
        pegtl::string<'N', 'u', 'l'>,
        pegtl::string<'B', 'o', 'o'>,
        pegtl::string<'R', 'e', 'g'>,
        pegtl::seq<
            pegtl::string<'L', 'i', 's', 't'>,
            pegtl::one<'<'>,
            Type,
            pegtl::one<'>'>
        >
    > {};

    //variable-------------------------------------------------

    //expression-----------------------------------------------

    struct Expression;
    struct FunctionCall : pegtl::seq<
        Identifier,
        pegtl::one<'('>,
        pegtl::star<Expression>,
        pegtl::one<')'>,
        End
    > {};

    struct ObjectCall : pegtl::seq<
        Identifier,
        pegtl::one<'.'>,
        Identifier,
        pegtl::one<'('>,
        pegtl::star<Expression>,
        pegtl::one<')'>,
        End
    > {};

    struct Reversing : pegtl::seq<
        pegtl::string<'r', 'e', 'v'>,
        End
    > {};

    struct Expression : pegtl::sor<
        Identifier,
        Literal,
        FunctionCall,
        ObjectCall,
        pegtl::seq<
            Expression,
            Operator,
            Expression
        >,
        pegtl::seq<
            pegtl::one<'('>,
            Expression,
            pegtl::one<')'>
        >,
        Regex,
        Reversing
    > {};

    //expression-----------------------------------------------

    //statement------------------------------------------------

    struct Statement;

    struct CaseState;
    struct ElseState;

    struct WhenState : pegtl::seq<
        pegtl::string<'w', 'h', 'e', 'n'>,
        pegtl::one<'{'>,
        pegtl::star<CaseState>,
        pegtl::opt<ElseState>,
        pegtl::one<'}'>,
        End
    > {};

    struct CaseState : pegtl::seq<
        pegtl::string<'c', 'a', 's', 'e'>,
        Expression,
        pegtl::one<':'>,
        pegtl::sor<
            pegtl::star<Statement>,
            pegtl::one<'{'>,
            pegtl::star<Statement>,
            pegtl::string<'e', 'n', 'd', '!'>,
            pegtl::one<'}'>
        >,
        End
    > {};

    struct ElseState : pegtl::seq<
        pegtl::string<'e', 'l', 's', 'e'>,
        pegtl::sor<
            pegtl::star<Statement>,
            pegtl::seq<
                pegtl::one<'{'>,
                pegtl::star<Statement>,
                pegtl::string<'e', 'n', 'd', '!'>,
                pegtl::one<'}'>
            >
        >,
        End 
    > {};

    struct FormatState : pegtl::seq<
        pegtl::sor<
            pegtl::string<'d', 'e', 'l'>,
            pegtl::string<'u', 'n', 'd', 'e', 'l'>
        >,
        Regex
    > {};

    struct ReturnState : pegtl::seq<
        pegtl::string<'r', 'e', 't'>,
        Expression, 
        End
    > {};


    struct Statement : pegtl::sor<
        Expression,
        WhenState,
        FormatState,
        ReturnState,
        End
    > {};

    //statement------------------------------------------------

    //argument-------------------------------------------------

    struct Argument : pegtl::seq<
        Type,
        Identifier,
        pegtl::opt<
            pegtl::seq<
                pegtl::one<'='>,
                Expression
            >
        >,
        End
    > {};

    //argument-------------------------------------------------

    //function-------------------------------------------------

    struct Block : pegtl::seq<
        pegtl::one<'{'>,
        pegtl::star<Statement>,
        pegtl::one<'}'>,
        End
    > {};

    struct Function : pegtl::seq<
        Type,
        Identifier,
        pegtl::one<'('>,
        pegtl::star<Argument>,
        pegtl::one<')'>,
        pegtl::sor<
            pegtl::seq<
                pegtl::one<'='>,
                pegtl::one<'>'>,
                Statement
            >,
            Block
        >,
        End
    > {};

    //function-------------------------------------------------

    //object---------------------------------------------------

    struct Object : pegtl::seq<
        pegtl::string<'o', 'b', 'j'>,
        Identifier,
        pegtl::one<'{'>,
        pegtl::star<Argument>,
        pegtl::star<Function>,
        pegtl::one<'}'>,
        End
    > {};

    //object---------------------------------------------------

    //Program--------------------------------------------------

    struct Main : pegtl::seq<
        pegtl::string<'I', 'n', 't'>,
        pegtl::string<'m', 'a', 'i', 'n'>,
        pegtl::one<'('>,
        pegtl::star<Argument>,
        pegtl::one<')'>,
        Block
    > {};

    struct Program : pegtl::seq<
        Main,
        pegtl::star<Function>,
        pegtl::star<Object>,
        pegtl::star<Function>
    > {};
    
    //Program--------------------------------------------------

    //selector-------------------------------------------------

    template< typename Rule >
    struct my_selector : std::false_type {};
    template<> struct my_selector< Type > : std::true_type {};
    template<> struct my_selector< Space > : std::false_type {};
}//namespace grammer

}//namespace ddlbx