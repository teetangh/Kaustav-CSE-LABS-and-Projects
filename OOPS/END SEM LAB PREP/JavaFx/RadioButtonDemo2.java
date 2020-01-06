import javafx.beans.value.*;
import javafx.application.*;
import javafx.beans.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.geometry.*;

public class RadioButtonDemo2 extends Application {
    Label response;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage myStage) throws Exception {
        myStage.setTitle("Radio Buttons");

        FlowPane rootNode = new FlowPane(10, 10);
        rootNode.setAlignment(Pos.CENTER);
        Scene myScene = new Scene(rootNode, 350,140);
        myStage.setScene(myScene);

        Label choose = new Label("Select a Transport Type");
        response = new Label("No Trnasport Confirmed");

        Button btnConfirm = new Button("Confirm Transport Selection");

        RadioButton rbTrain = new RadioButton("Train");
        RadioButton rbCar = new RadioButton("Car");
        RadioButton rbPlane = new RadioButton("Airplane");

        ToggleGroup tg = new ToggleGroup();
        rbTrain.setToggleGroup(tg);
        rbCar.setToggleGroup(tg);
        rbPlane.setToggleGroup(tg);

        rbTrain.setSelected(true);

        btnConfirm.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent event) {
                RadioButton rb = (RadioButton) tg.getSelectedToggle();
                response.setText(rb.getText() + " is Confirmed");
            }
        });

        Separator separator = new Separator();
        separator.setPrefWidth(180);

        rootNode.getChildren().addAll(choose,rbTrain, rbCar, rbPlane, separator, btnConfirm, response);

        myStage.show();

    }
}