// language-specific.ts
export const keywords = [
  "auto",
  "Bool",
  "break",
  "case",
  "char",
  "class",
  "const",
  "continue",
  "default",
  "delete",
  "do",
  "double",
  "else",
  "enum",
  "explicit",
  "export",
  "extern",
  "false",
  "Float",
  "for",
  "func",
  "goto",
  "if",
  "inline",
  "Int",
  "long",
  "mutable",
  "namespace",
  "new",
  "nullptr",
  "operator",
  //obj -> object
  "obj",
  "print",
  "register",
  "return",
  "short",
  "signed",
  "sizeof",
  "static",
  "struct",
  "String",
  "switch",
  "template",
  "this",
  "throw",
  "true",
  "try",
  "union",
  "unsigned",
  "using",
  "virtual",
  "void",
  "volatile",
  "while"
];

export const types = {
  integer: [
    "Int",
  ],
  float: [
    "Float",
    "double"
  ],
  string: [
    "String"
  ],
  boolean: [
    "Bool"
  ],
  void: [
    "void"
  ]
};

export const operators = {
  arithmetic: [
    "+",
    "-",
    "*",
    "/",
    "%",
    "++",
    "--",
    "+=",
    "-=",
    "*=",
    "/=",
    "%="
  ],
  comparison: [
    "==",
    "!=",
    ">",
    "<",
    ">=",
    "<="
  ],
  logical: [
    "&&",
    "||",
    "!"
  ],
  bitwise: [
    "&",
    "|",
    "^",
    "~",
    "<<",
    ">>",
    "&=",
    "|=",
    "^=",
    "~=",
    "<<=",
    ">>="
  ],
  special: [
    "^",
    "v",
    "~",
  ]
};

export const ArithmeticOperators = [
  "+",
  "-",
  "*",
  "/",
  "%",
  "++",
  "--",
  "+=",
  "-=",
  "*=",
  "/=",
  "%="
];

export const ComparisonOperators = [
  "==",
  "!=",
  ">",
  "<",
  ">=",
  "<="
];

export const LogicalOperators = [
  "&&",
  "||",
  "!"
];

export const BitwiseOperators = [
  "&",
  "|",
  "^",
  "~",
  "<<",
  ">>",
  "&=",
  "|=",
  "^=",
  "~=",
  "<<=",
  ">>="
];

export const SpecialOperators = [
  "^",
  "v",
  "~",
];

export const literals = [
  "123",
  "'abc'",
  "true",
  "false"
];
