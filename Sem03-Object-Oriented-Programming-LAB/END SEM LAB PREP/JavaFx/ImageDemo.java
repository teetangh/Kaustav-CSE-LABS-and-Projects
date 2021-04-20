import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.geometry.*;
import javafx.scene.image.*;

public class ImageDemo extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    public void start(Stage myStage) {
        myStage.setTitle("Displaying an Image");
        FlowPane rootNode = new FlowPane();
        rootNode.setAlignment(Pos.CENTER);
        Scene myScene = new Scene(rootNode, 300, 200);
        myStage.setScene(myScene);

        Image hourglass = new Image("hourglass.jpg");
        ImageView hourglassIV = new ImageView(hourglass);

        rootNode.getChildren().addAll(hourglassIV);
        myStage.show();
    }
}