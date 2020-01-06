import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.event.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.geometry.*;
import javafx.beans.value.*;
import javafx.collections.*;

public class ComboBoxDemo extends Application {
    Label response;
    ComboBox<String> cbTransport;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage myStage) throws Exception {
        myStage.setTitle("ComboBOX Demo");

        FlowPane rootNode = new FlowPane(10, 10);
        rootNode.setAlignment(Pos.CENTER);

        Scene myScene = new Scene(rootNode, 200, 120);
        myStage.setScene(myScene);

        response = new Label();

        ObservableList<String> transportTypes = FXCollections.observableArrayList("Train", "Car", "Airplane");

        cbTransport = new ComboBox<String>(transportTypes);
        cbTransport.setValue("Train");
        response.setText("Selected Transport is " + cbTransport.getValue());

        cbTransport.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent ae) {
                response.setText("Selected Transport is " + cbTransport.getValue());
            }
        });

        rootNode.getChildren().addAll(cbTransport, response);
        myStage.show();
    }
}