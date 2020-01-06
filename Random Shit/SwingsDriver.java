import javax.swing.*;
import java.awt.event.*;
import java.util.*;

class FirstSwingExample {

  MovieInfo movie_info;

  // Layout variables
  JButton button;
  JFrame frame;

  JLabel nameLabel;
  JLabel earningsLabel;

  JTextField nameField;
  JTextField earningsField;

  private void viewDidLoad() {

    button = new JButton("Click");

    //set bounds defines the region of the UI element to be added to the frame
    button.setBounds(130, 170, 100, 40); // x axis, y axis, width, height

    frame = new JFrame();
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


    frame.setSize(400, 500); // sets the dimension of the frame
    frame.setLayout(null); // using no layout managers


    nameField = new JTextField();
    nameField.setBounds(50, 50, 220,50);

    earningsField = new JTextField();
    earningsField.setBounds(50, 110, 220, 50);

    nameLabel = new JLabel();
    nameLabel.setBounds(50, 300, 100, 30);

    earningsLabel = new JLabel();
    earningsLabel.setBounds(50, 340, 100, 30);

    nameField.setText("Type Name here..");
    earningsField.setText("Type Earnings here..");

    button.addActionListener(new ActionListener() {

      public void actionPerformed(ActionEvent event) {
        addActionListener();
      }

    });

    frame.add(button);
    frame.add(nameField);
    frame.add(earningsField);
    frame.add(nameLabel);
    frame.add(earningsLabel);

    frame.setVisible(true);

  }


  FirstSwingExample() {

    viewDidLoad();

  }

  private void delegate_for(MovieInfo movie_info) {
    this.movie_info = movie_info;
  }

  public void addActionListener() {

    movie_info = new MovieInfo(nameField.getText(), Integer.parseInt(earningsField.getText()));

    nameLabel.setText(movie_info.getName());
    earningsLabel.setText(Integer.toString(movie_info.getEarnings()));
  }

  public void setLabelText() {

  }

  public void integrate() {

  }

}

class MovieInfo {

  private String name;
  private int earnings;

  MovieInfo(String name, int earnings) {
    this.name = name;
    this.earnings = earnings;
  }

  public String getName() {
    return name;
  }

  public int getEarnings() {
    return earnings;
  }


}

class CalculatorSwings {

  JFrame frame;

  JTextField operand1;
  JTextField operand2;

  JLabel result;

  JButton add;
  JButton subtract;
  JButton divide;
  JButton multiply;

  private void viewDidLoad() {

    frame = new JFrame();
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setVisible(true);

    frame.setSize(400, 400);

    add = new JButton("+");
    add.setBounds(120, 250, 20, 20);

    add.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent event) {
        performAddition();
      }
    });

    subtract = new JButton("-");
    subtract.setBounds(150, 250, 20, 20);

    subtract.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent event) {
        performSubtraction();
      }
    });

    divide = new JButton("/");
    divide.setBounds(180, 250, 20, 20);

    multiply = new JButton("x");
    multiply.setBounds(210, 250, 20, 20);

    frame.add(add);
    frame.add(subtract);
    frame.add(divide);
    frame.add(multiply);

    // Set operand textField
    operand1 = new JTextField();
    operand1.setBounds(50, 110, 220, 50);

    operand2 = new JTextField();
    operand2.setBounds(50, 160, 220, 50);

    frame.add(operand1);
    frame.add(operand2);

    //Set result label
    result = new JLabel();
    result.setBounds(50, 280, 60, 60);

    frame.add(result);

  }


  private void performAddition() {

    int a = Integer.parseInt(operand1.getText());
    int b = Integer.parseInt(operand2.getText());

    result.setText(Integer.toString(a + b));

  }

  private void performSubtraction() {
    int a = Integer.parseInt(operand1.getText());
    int b = Integer.parseInt(operand2.getText());

    result.setText(Integer.toString(a - b));
  }

  CalculatorSwings() {
    viewDidLoad();
  }

}

class StringSwings {

  //initialize view

  JTextField str_field;
  JButton search_button;
  JButton add_button;
  JLabel found_label;
  JLabel search_label;
  JFrame frame;

  //model
  List<String> string_list;

  private void viewDidLoad(List<String> string_list) {
    //initialize model
    this.string_list = string_list;

    frame = new JFrame();
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setSize(500, 500);

    str_field = new JTextField();
    str_field.setText("Enter string:");
    str_field.setBounds(50, 220, 150, 50);

    search_button = new JButton("Search");
    search_button.setBounds(50, 280, 70, 50);

    add_button = new JButton("Add");
    add_button.setBounds(130, 280, 70, 50);

    found_label = new JLabel();
    found_label.setBounds(250, 250, 70, 70);

    search_label = new JLabel("Searched");
    search_label.setBounds(150, 180, 70, 70);

    frame.add(str_field);
    frame.add(search_button);
    frame.add(add_button);
    frame.add(found_label);
    //frame.add(search_label);

    frame.setVisible(true);
    frame.setLayout(null);

    add_string();
    search_string();
  }

  StringSwings(List<String> string_list) {

    viewDidLoad(string_list);

  }

  //define controllers

  private void add_string() {

    add_button.addActionListener(new ActionListener() {

      public void actionPerformed(ActionEvent event) {

        String text = str_field.getText();
        string_list.add(text);
        System.out.println("Text added");

        str_field.setText("Enter or search text: ");

      }

    });

  }

  private void search_string() {

    search_button.addActionListener(new ActionListener() {

      public void actionPerformed(ActionEvent event) {

        String text = str_field.getText();
        int index = string_list.indexOf(text);

        if(index != -1) {

          System.out.println("Found!");
          String search_hit = string_list.get(index);
          System.out.println(search_hit);
          found_label.setText(search_hit);

        } else {
          System.out.println("Not found");
          found_label.setText("Not found");
        }

        //found_label.setText("");
      }

    });
  }

}

public class SwingsDriver {
  public static void main(String[] args) {

    List<String> string_list = new ArrayList<String>();

    //new FirstSwingExample();
    new CalculatorSwings();
    //new StringSwings(string_list);
  }
}