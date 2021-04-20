import javafx.application.*;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.geometry.*;
import javafx.scene.image.*;

public class ButtonImageDemo extends Application {
    Label response;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage myStage) throws Exception {
        myStage.setTitle("Use an Image with Buttons");
        FlowPane rootNode = new FlowPane(10, 10);
        rootNode.setAlignment(Pos.CENTER);
        Scene myScene = new Scene(rootNode, 250, 450);
        myStage.setScene(myScene);

        response = new Label("Push a button");

        Button btnHourglass = new Button("Hourglass", new ImageView("hourglass.jpg"));
        Button btnAnalogClock = new Button("Analog Clock", new ImageView("analog.jpg"));

        btnHourglass.setContentDisplay(ContentDisplay.TOP);
        btnAnalogClock.setContentDisplay(ContentDisplay.TOP);

        btnHourglass.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent event) {
                // TODO Auto-generated method stub
                response.setText("HourGlass Pressed");
            }
        });

        btnAnalogClock.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent ae) {
                response.setText("Analog Clock was pressed");
            }
        });

        rootNode.getChildren().addAll(btnHourglass, btnAnalogClock, response);
        myStage.show();

    }
}