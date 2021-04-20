import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.geometry.*;

public class ToggleButtonDemo extends Application {

    ToggleButton tbOnOff;
    Label response;

    public static void main(String[] args) {
        launch(args);

    }

    public void start(Stage myStage) {
        myStage.setTitle("Toggle Buttons");
        FlowPane rootNode = new FlowPane(10, 10);
        Scene myScene = new Scene(rootNode, 300,300);
        rootNode.setAlignment(Pos.CENTER);

        myStage.setScene(myScene);

        response = new Label("Push the Button");
        tbOnOff = new ToggleButton("On/Off");

        tbOnOff.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                if (tbOnOff.isSelected())
                    response.setText("Button is On");
                else
                    response.setText("Button is off");

            }
        });

        rootNode.getChildren().addAll(tbOnOff, response);
        myStage.show();

    }
}
