import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.geometry.*;

public class JavaFXEventDemo extends Application {
    Label response;

    public static void main(String[] args) {
        // Start the JavaFX application by calling launch()
        launch(args);
    }

    // Override the start() method.
    public void start(Stage myStage) {
        // Give the stage a title
        myStage.setTitle("Use the JavaFX Buttons and Events");
        // Use a FlowPAne for the root node.In this
        // case, vertical and horizontal gaps of 10.
        FlowPane rootNode = new FlowPane(10, 10);
        // Center the controls in the scene.
        rootNode.setAlignment(Pos.CENTER);
        // Create a scene.
        Scene myScene = new Scene(rootNode, 300, 100);

        // set the Scene on the stage.
        myStage.setScene(myScene);
        // Create a label.
        response = new Label("Push a button");
        // Create 2 push buttons.
        Button btnUp = new Button("Up");
        Button btnDown = new Button("Down");
        // Handle the action events for the UP Button.
        btnUp.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent ae) {
                response.setText("You pressed Up.");

            }
        });
        // Handle the action events for the DOWN Button.
        btnDown.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent ae) {
                response.setText("You pressed Down.");

            }
        });

        // Add the label and buttons to the scene graph.
        rootNode.getChildren().addAll(btnUp, btnDown, response);
        // Show the stage and its scene
        myStage.show();

    }

}