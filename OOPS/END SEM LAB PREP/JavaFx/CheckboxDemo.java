import javafx.application.*;
import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.event.*;
import javafx.geometry.*;

public class CheckboxDemo extends Application {

    CheckBox cbWeb;
    CheckBox cbDesktop;
    CheckBox cbMobile;

    Label response;
    Label allTargets;

    String targets = "";

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage myStage) throws Exception {
        myStage.setTitle("Check Boxes");

        FlowPane rootNode = new FlowPane(10, 10);
        rootNode.setAlignment(Pos.CENTER);
        Scene myScene = new Scene(rootNode, 230, 140);
        myStage.setScene(myScene);

        Label heading = new Label("Select Deployment Options");

        response = new Label("No Deployment Selected");
        allTargets = new Label("Target List: <None>");

        cbWeb = new CheckBox("web");
        cbDesktop = new CheckBox("Desktop");
        cbMobile = new CheckBox("Mobile");

        cbWeb.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent ae) {
                if (cbWeb.isSelected())
                    response.setText("Web Delpoyment Selected");
                else
                    response.setText("Web Delpoyment Cleared");
                showAll();
            }

        });

        cbDesktop.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent ae) {
                if (cbWeb.isSelected())
                    response.setText("Desktop Delpoyment Selected");
                else
                    response.setText("Desktop Delpoyment Cleared");
                showAll();
            }

        });

        cbMobile.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent ae) {
                if (cbWeb.isSelected())
                    response.setText("Mobile Delpoyment Selected");
                else
                    response.setText("Mobile Delpoyment Cleared");
                showAll();
            }

        });

        Separator separator = new Separator();
        separator.setPrefWidth(200);

        rootNode.getChildren().addAll(heading, separator, cbWeb, cbDesktop, cbMobile, response, allTargets);

        myStage.show();

    }

    void showAll() {
        targets = "";
        if (cbWeb.isSelected())
            targets = " Web ";
        if (cbDesktop.isSelected())
            targets += " Desktop ";
        if (cbMobile.isSelected())
            targets += " Mobile ";

        allTargets.setText("Target List:" + targets);
    }
}