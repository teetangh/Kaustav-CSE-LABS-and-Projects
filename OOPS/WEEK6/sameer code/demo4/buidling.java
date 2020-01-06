package com.course.structure;
import java.util.*;/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author sameer admin
 */
public class buidling {
    int stories;
    double area;
    
public buidling()
{
    System.out.println("Enter stories and square footage");
    Scanner s=new Scanner(System.in);
    stories=s.nextInt();
    area=s.nextDouble();
    
}
public int s()
{
    return stories;
}
public double a()
{
    return area;
}
}

