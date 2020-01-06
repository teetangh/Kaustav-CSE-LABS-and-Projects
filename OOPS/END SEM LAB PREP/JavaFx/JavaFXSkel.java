import java.util.concurrent.Flow;

import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;

public class JavaFXSkel extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    public void init() {
        System.out.println("Inside th init method");
    }

    public void start(Stage myStage) {
        System.out.println("Inside the start method");
        myStage.setTitle("JavaFX Skeleton");

        FlowPane rootNode = new FlowPane();
        Scene myScene = new Scene(rootNode, 300, 500);
        myStage.setScene(myScene);

        myStage.show();
    }

    public void stop() {
        System.out.println("Inside the Stop method");
    }

}
