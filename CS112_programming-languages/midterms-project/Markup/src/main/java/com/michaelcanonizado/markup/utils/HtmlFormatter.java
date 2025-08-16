/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.michaelcanonizado.markup.utils;

import java.util.List;
import java.util.Map;
import java.util.Stack;

/**
 *
 * @author lilac
 */
public class HtmlFormatter {
    private static final Map<String, String> TAGS = Map.of(
        "\\blockquote", "blockquote",
        "\\h1", "h1",
        "\\h2", "h2",
        "\\h3", "h3",
        "\\p", "p",
        "\\b", "b",
        "\\i", "i",
        "\\u", "u",
        "\\s", "s",
        "\\li", "li"
    );

    public static String formatHtml(String text, List<String> escapeChars) {
        StringBuilder sb = new StringBuilder();
        Stack<String> tagStack = new Stack<>();
        
        sb.append("<html>");
        
        for (String escape : escapeChars) {
            if (TAGS.containsKey(escape)) {
                String tag = TAGS.get(escape);
                sb.append("<").append(tag).append(">");
                tagStack.push(tag);
            }
        }
        
        sb.append(text);
        
        while (!tagStack.isEmpty()) {
            sb.append("</").append(tagStack.pop()).append(">");
        }
        
        sb.append("</html>");
        
        return sb.toString();
    }
}
