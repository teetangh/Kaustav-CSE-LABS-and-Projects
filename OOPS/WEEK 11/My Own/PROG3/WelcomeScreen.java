import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.geometry.*;

public class WelcomeScreen extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    public void start(Stage myStage) {
        myStage.setTitle("JavaFx Welcome");
        GridPane gridPane = new GridPane();
        Scene myScene = new Scene(gridPane, 300, 100);
        myStage.setScene(myScene);

        Label L1 = new Label();
        L1.setText("Name \n");

        TextField T = new TextField();
        T.setPromptText("Your Name");

        Label L2 = new Label();
        L2.setText("Password");

        PasswordField P = new PasswordField();
        P.setPromptText("Your password");

        Button signINButton = new Button("Sign In");
        // gridPane.add(Button, x, y, xspan, yspan);
        gridPane.add(L1, 0, 0, 1, 1);
        gridPane.add(T, 1, 0, 2, 1);
        gridPane.add(L2, 0, 1, 2, 1);
        gridPane.add(P, 2, 1, 1, 1);
        gridPane.add(signINButton, 3, 5, 2, 1);

        Label response = new Label("Sign in Please");
        gridPane.add(response, 1, 5, 2, 1);

        signINButton.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent ae) {
                response.setText("Welcome " + T.getText());

            }
        });

        myStage.show();
    }
}