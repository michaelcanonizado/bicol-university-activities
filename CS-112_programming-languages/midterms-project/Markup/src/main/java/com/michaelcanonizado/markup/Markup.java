/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.michaelcanonizado.markup;
import com.michaelcanonizado.markup.frames.pages.Index;
import com.michaelcanonizado.markup.utils.Parser;
import com.michaelcanonizado.markup.utils.ParserResult;

/**
 *
 * @author lilac
 */
public class Markup {

    public static void main(String[] args) {
//        String input = "\\h\\hello\\x\\p1";
//        String input = "\\p1\\h\\p1\\helloHello World! This is Michael XD;"
//                + "\n\\h\\helloMy name is mike!;";
////        String input = "World!;";
//        Parser parser = new Parser(input);
//        
//        System.out.println("Input: " + input);
//        System.out.println("Input Length: " + input.length());
//        ParserResult result = parser.parse();
//        System.out.println(result);
//        System.out.println(result.getStatements());
        
        java.awt.EventQueue.invokeLater(() -> {
            Index pages = new Index();
            pages.setVisible(true);
        });
    }
}
