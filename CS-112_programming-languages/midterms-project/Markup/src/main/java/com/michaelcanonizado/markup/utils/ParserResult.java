/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.michaelcanonizado.markup.utils;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author lilac
 */
public class ParserResult {
    private boolean isValid;
    private int errorIndex;
    private String errorMessage;
    private String errorContext;
    private List<StatementData> statements = new ArrayList<>();

    public ParserResult(boolean isValid, int errorIndex, String errorMessage, String errorContext) {
        this.isValid = isValid;
        this.errorIndex = errorIndex;
        this.errorMessage = errorMessage;
        this.errorContext = errorContext;
    }

    public boolean getIsValid() {
        return isValid;
    }

    public int getErrorIndex() {
        return errorIndex;
    }

    public String getErrorMessage() {
        return errorMessage;
    }

    public String getErrorContext() {
        return errorContext;
    }
    
    public List<StatementData> getStatements() {
        return statements;
    }

    public void setIsValid(boolean isValid) {
        System.out.println("SETTING ISVALID: "+isValid);
        this.isValid = isValid;
    }

    public void setErrorIndex(int errorIndex) {
        this.errorIndex = errorIndex;
    }

    public void setErrorMessage(String errorMessage) {
        this.errorMessage = errorMessage;
    }

    public void setErrorContext(String errorContext) {
        this.errorContext = errorContext;
    }
    
    public void setStatements(List<StatementData> statements) {
        this.statements = statements;
    }
    
    @Override
    public String toString() {
        if (isValid) {
            return "Parsing successful!";
        }
        return "\tParsing failed at index " + errorIndex + 
                ":\n\tError Message: " + errorMessage +
                "\n\tContext: " + errorContext;
    }
}
