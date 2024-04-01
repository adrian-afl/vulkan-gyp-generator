module.exports = {
  root: true,
  parser: "@typescript-eslint/parser",
  extends: [
    "eslint:recommended",
    "plugin:@typescript-eslint/recommended",
    "plugin:@typescript-eslint/recommended-requiring-type-checking",
    "plugin:@typescript-eslint/strict",
  ],
  plugins: ["@typescript-eslint/eslint-plugin", "import", "prettier"],
  env: {
    node: true,
    es6: true,
    mocha: true,
  },
  parserOptions: {
    ecmaVersion: 2020,
    sourceType: "module",
    project: "tsconfig.json",
  },
  rules: {
    "prettier/prettier": "error",
    semi: ["off"],
    eqeqeq: "error",
    quotes: "off",

    // ah yes, parsing xml
    "@typescript-eslint/no-explicit-any": "off",
    "@typescript-eslint/no-unsafe-assignment": "off",
//    "@typescript-eslint/no-unsafe-call": "off",
    "@typescript-eslint/no-unsafe-member-access": "off",
    "@typescript-eslint/no-unsafe-call": "off",
    "@typescript-eslint/no-unsafe-return": "off",
    "@typescript-eslint/no-unsafe-argument": "off",

    "prefer-const": "error",
    // "no-console": "error",
    "linebreak-style": ["error", "unix"],
    "comma-dangle": ["warn", "only-multiline"],
    "@typescript-eslint/explicit-function-return-type": [
      "error",
      { allowExpressions: true },
    ],
    "@typescript-eslint/semi": ["error", "always"],
    "@typescript-eslint/no-non-null-assertion": "off",
    "@typescript-eslint/explicit-member-accessibility": ["error"],
    "@typescript-eslint/no-inferrable-types": [
      "warn",
      {
        ignoreParameters: true,
      },
    ],
    "@typescript-eslint/no-unused-vars": [
      "warn",
      {
        argsIgnorePattern: "^_",
        varsIgnorePattern: "^_",
        caughtErrorsIgnorePattern: "^_",
      },
    ],
    // "@typescript-eslint/member-ordering": ["error"],
    "@typescript-eslint/interface-name-prefix": "off",
    "@typescript-eslint/explicit-module-boundary-types": "off",
    "import/no-default-export": 2,
    "@typescript-eslint/no-unnecessary-type-assertion": ["error"],
    "@typescript-eslint/naming-convention": [
      "error",
      {
        selector: [
          "variable",
          "classProperty",
          "function",
          "parameter",
          "typeProperty",
          "parameterProperty",
          "classMethod",
          "objectLiteralMethod",
          "typeMethod",
          "accessor",
        ],
        format: ["camelCase"],
        leadingUnderscore: "allow",
      },
      {
        selector: [
          "class",
          "interface",
          "enum",
          "enumMember",
          "typeAlias",
          "typeParameter",
        ],
        format: ["PascalCase"],
      },
    ],
  },
  ignorePatterns: [".eslintrc.js", "tsconfig*.json", "testoutdir/*", "examples/examplebuild/*"],
};
