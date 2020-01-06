import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;

public class JavaFXLabelDemo extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    public void start(Stage myStage) {
        myStage.setTitle("Demonstrate a JavaFX Label");
        FlowPane rootNode = new FlowPane();

        Scene myScene = new Scene(rootNode, 300, 200);
        myStage.setScene(myScene);

        Label myLabel = new Label("This is a JavaFX Label");
        rootNode.getChildren().add(myLabel);

        myStage.show();
    }
}
