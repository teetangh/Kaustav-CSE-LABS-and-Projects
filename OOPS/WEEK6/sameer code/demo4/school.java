/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.course.structure;
import java.util.*;
/**
 *
 * @author sameer admin
 */
public class school extends house {
    String classroom,grade;
    public school()
    {
        super();
        Scanner s=new Scanner(System.in);
        System.out.println("Enter class and grade level");
        classroom=s.nextLine();
        grade=s.nextLine();
    }
    public String c()
    {
        return classroom;
    }
    public String grade()
    {
        return grade;
    }

            
}
