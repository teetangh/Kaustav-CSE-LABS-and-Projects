import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.geometry.*;
import javafx.scene.image.*;

public class LabelImageDemo extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage myStage) throws Exception {
        myStage.setTitle("Use an Image in a Label");
        FlowPane rootNode = new FlowPane();
        rootNode.setAlignment(Pos.CENTER);
        Scene myScene = new Scene(rootNode, 300, 200);
        myStage.setScene(myScene);

        ImageView hourglassIV = new ImageView("hourglass.jpg");
        Label hourglassLabel = new Label("Hourglass", hourglassIV);
        hourglassLabel.setContentDisplay(ContentDisplay.BOTTOM);
        rootNode.getChildren().addAll(hourglassLabel);
        myStage.show();

    }
}