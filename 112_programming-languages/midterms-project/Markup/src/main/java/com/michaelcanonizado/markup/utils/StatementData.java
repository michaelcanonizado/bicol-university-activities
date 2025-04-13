/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.michaelcanonizado.markup.utils;

import java.util.List;

/**
 *
 * @author lilac
 */
public class StatementData {
    private List<String> escapeSequences;
    private String text = null;

    public StatementData(List<String> escapeSequences, String text) {
        this.escapeSequences = escapeSequences;
        this.text = text;
    }
    
    @Override
    public String toString() {
        return "EscapeSequences: " + escapeSequences + ", Text: \"" + text + "\"";
    }

    public List<String> getEscapeSequences() {
        return escapeSequences;
    }

    public String getText() {
        return text;
    }
}
