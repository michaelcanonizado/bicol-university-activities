# Markup📝

Welcome to **Markup**! A custom Markdown-like language built as a project for **CS112 (Programming Languages)**! 🚀 This project involved designing our own language, writing its grammars, and implementing the parser. Initially, I wanted to create a [Markdown](https://markdownlivepreview.com/) parser; but after researching, I found that Markdown isn’t context-free. So I built my own Markdown instead! 😎

## Features✨
- ✅ Supports escape sequences for common text formatting (like headings, paragraphs, bold, italics, etc.)
- ✅ Supports nested styles. E.g: A bold list item that's also italicized
- ✅ Efficient recursive descent parsing
- ✅ Interactive GUI

## GUI🖥️
![image](https://github.com/user-attachments/assets/7c1e1e18-7cff-420c-9f36-19836dbe77aa)


## Syntax✍
Markup uses **escape sequences** to define different text styles.\
The syntax is as follows:
```
<escape_sequence><string>;
```
Where a string can contain any alphanumeric character and symbols apart from ';' and '\\'.\
A single line should always start with an escape sequence and terminated with a ';'.

## Supported Escape Sequences🔹
| Escape Sequence | Style applied|
|----------------|--------------|
| `\h1`          | Heading 1     |
| `\h2`          | Heading 2     |
| `\h3`          | Heading 3     |
| `\p`           | Paragraph     |
| `\b`           | Bold          |
| `\i`           | Italics       |
| `\u`           | Underline     |
| `\s`           | Strikethrough |
| `\li`          | List item     |
| `\blockquote`  | Blockquote    |


## Example Input 📥
```
\liThis is a list item!;
\p\bThis is a bold paragraph;
\iand this is an italic text :D;
```
## Output 📥
- This is a list item!\
**This is a bold paragraph**\
_and this is an italic text :D_

## Context-Free Grammar (CFG) 📜
This is the CFG that defines the syntax of the Markup language:
```
              <program> ::= <statement><program> | ε
            <statement> ::= <escape_sequences><string> ;
     <escape_sequences> ::= <escape_sequence><escape_sequences_tail>
<escape_sequences_tail> ::= <escape_sequence><escape_sequences_tail> | ε
      <escape_sequence> ::= \<escape_character>
     <escape_character> ::= "blockquote" | "h1" | "h2" | "h3" | "p" | "b" | "i" | "u" | "s" | "li"
               <string> ::= <character><string> | ε
            <character> ::= <letter> | <number> | <symbol>
               <letter> ::= a | b | c | ... | z | A | B | C | ... | Z
               <number> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
               <symbol> ::= ! | # | $ | % | & | ' | ( | ) | * | + | , | - | . | / | : | < | = | > | ? | @ | [ | ] | ^ | _ | ` | { | | | } | ~
```

## Running the Project 🚀
1. Clone this repository or download the source code.
2. Open the project in your IDE.
3. Compile and run the **main Java file** that starts the Swing interface.
4. Enter your Markup-formatted text, click run, and see the parsed results!

