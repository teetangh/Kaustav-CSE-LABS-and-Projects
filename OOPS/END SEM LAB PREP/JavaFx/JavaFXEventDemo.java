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
        launch(args);
    }

    public void start(Stage myStage) {
        myStage.setTitle("Demosntrate JavaFX Buttons and Events");

        FlowPane rootNode = new FlowPane();
        rootNode.setAlignment(Pos.CENTER);
        Scene myScene = new Scene(rootNode, 300, 100);
        myStage.setScene(myScene);
        response = new Label("Push a button");

        Button btnAlpha = new Button("Alpha");
        Button btnBeta = new Button("Beta");

        btnAlpha.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent ae) {
                response.setText("Alpha was pressed.");
            }
        });

        btnBeta.setOnAction(e -> {
            response.setText("Beta was pressed.");
        });

        rootNode.getChildren().addAll(btnAlpha, btnBeta, response);
        myStage.show();

    }
}