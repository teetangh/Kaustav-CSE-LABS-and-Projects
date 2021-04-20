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
public class house extends buidling {
    int bed,bath;
    public house()
    {
        super();
        System.out.println("Enter number of bedrooms amd bathrooms");
        Scanner s=new Scanner(System.in);
        bed=s.nextInt();
        bath=s.nextInt();
        
    }
   public int bed()
    {
        return bed;
    }
   public int bath()
    {
        return bath;
    }
    
}
