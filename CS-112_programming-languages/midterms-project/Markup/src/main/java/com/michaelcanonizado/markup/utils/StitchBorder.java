/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.michaelcanonizado.markup.utils;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Component;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.border.AbstractBorder;

/**
 *
 * @author lilac
 */
public class StitchBorder extends AbstractBorder {
    private final float[] dashPattern = {2, 3}; // Shorter dashes for a subtle stitch effect
    private final Color borderColor = Color.decode("#27272A"); // Custom color
    private final int sides; // Sides to be drawn

    // Constants for specifying sides
    public static final int TOP = 1;
    public static final int LEFT = 2;
    public static final int BOTTOM = 4;
    public static final int RIGHT = 8;
    public static final int ALL = TOP | LEFT | BOTTOM | RIGHT;

    public StitchBorder(int sides) {
        this.sides = sides;
    }

    @Override
    public void paintBorder(Component c, Graphics g, int x, int y, int width, int height) {
        Graphics2D g2d = (Graphics2D) g.create();
        g2d.setColor(borderColor);
        g2d.setStroke(new BasicStroke(1, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND, 0, dashPattern, 0));

        if ((sides & TOP) != 0) g2d.drawLine(x + 1, y + 1, x + width - 2, y + 1); // Top border
        if ((sides & LEFT) != 0) g2d.drawLine(x + 1, y + 1, x + 1, y + height - 2); // Left border
        if ((sides & BOTTOM) != 0) g2d.drawLine(x + 1, y + height - 2, x + width - 2, y + height - 2); // Bottom border
        if ((sides & RIGHT) != 0) g2d.drawLine(x + width - 2, y + 1, x + width - 2, y + height - 2); // Right border

        g2d.dispose();
    }
}
