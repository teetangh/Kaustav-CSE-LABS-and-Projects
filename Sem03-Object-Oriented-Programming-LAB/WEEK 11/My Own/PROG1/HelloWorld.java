import javafx.scene.control.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;

public class HelloWorld extends Application {
    public void start(Stage primaryStage) {
        primaryStage.setTitle("This is the first JavaFX Application");
        Label lbl = new Label();
        lbl.setText("Welcome to JavaFX Programming");
        lbl.setTextFill(Color.MAGENTA);

        FlowPane root = new FlowPane(1000, 2000);
        // root.setVgap(1000);
        // root.setHgap(2000);
        root.getChildren().add(lbl);
        Scene myScene = new Scene(root, 500, 200);
        primaryStage.setScene(myScene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);

    }

}