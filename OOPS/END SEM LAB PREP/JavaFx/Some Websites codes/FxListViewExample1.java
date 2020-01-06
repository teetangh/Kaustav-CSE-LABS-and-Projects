import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.geometry.Orientation;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TextArea;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class FxListViewExample1 extends Application {
    // Declaring the TextArea for Logging
    TextArea logging;

    public static void main(String[] args) {
        Application.launch(args);
    }

    @Override
    public void start(Stage stage) {
        // Create the TextArea
        logging = new TextArea();
        logging.setMaxWidth(300);
        logging.setMaxHeight(150);

        // Create the Labels
        Label seasonLbl = new Label("Select Season: ");
        Label fruitLbl = new Label("Select Fruit: ");

        // Create the Lists for the ListViews
        ObservableList<String> seasonList = FXCollections.<String>observableArrayList("Spring", "Summer", "Fall",
                "Winter");
        ObservableList<String> fruitList = FXCollections.<String>observableArrayList("Apple", "Banana", "Orange",
                "Mango");

        // Create the ListView for the seasons
        ListView<String> seasons = new ListView<>(seasonList);
        // Set the Orientation of the ListView
        seasons.setOrientation(Orientation.VERTICAL);
        // Set the Size of the ListView
        seasons.setPrefSize(120, 100);

        // Update the TextArea when the selected season changes
        seasons.getSelectionModel().selectedItemProperty().addListener(new ChangeListener<String>() {
            public void changed(ObservableValue<? extends String> ov, final String oldvalue, final String newvalue) {
                seasonChanged(ov, oldvalue, newvalue);
            }
        });

        // Create the ListView for the fruits
        ListView<String> fruits = new ListView<String>();
        // Set the Orientation of the ListView
        fruits.setOrientation(Orientation.HORIZONTAL);
        // Set the Size of the ListView
        fruits.setPrefSize(200, 100);
        // Add the items to the ListView
        fruits.getItems().addAll(fruitList);

        // Update the message Label when the selected fruit changes
        fruits.getSelectionModel().selectedItemProperty().addListener(new ChangeListener<String>() {
            public void changed(ObservableValue<? extends String> ov, final String oldvalue, final String newvalue) {
                fruitChanged(ov, oldvalue, newvalue);
            }
        });

        // Create the Season VBox
        VBox seasonSelection = new VBox();
        // Set Spacing to 10 pixels
        seasonSelection.setSpacing(10);
        // Add the Label and the List to the VBox
        seasonSelection.getChildren().addAll(seasonLbl, seasons);

        // Create the Fruit VBox
        VBox fruitSelection = new VBox();
        // Set Spacing to 10 pixels
        fruitSelection.setSpacing(10);
        // Add the Label and the List to the VBox
        fruitSelection.getChildren().addAll(fruitLbl, fruits);

        // Create the GridPane
        GridPane pane = new GridPane();
        // Set the horizontal and vertical gaps between children
        pane.setHgap(10);
        pane.setVgap(5);
        // Add the Season List at position 0
        pane.addColumn(0, seasonSelection);
        // Add the Fruit List at position 1
        pane.addColumn(1, fruitSelection);
        // Add the TextArea at position 2
        pane.addColumn(2, logging);

        // Set the Style-properties of the GridPane
        pane.setStyle("-fx-padding: 10;" + "-fx-border-style: solid inside;" + "-fx-border-width: 2;"
                + "-fx-border-insets: 5;" + "-fx-border-radius: 5;" + "-fx-border-color: blue;");

        // Create the Scene
        Scene scene = new Scene(pane);
        // Add the Scene to the Stage
        stage.setScene(scene);
        // Set the Title
        stage.setTitle("A simple ListView Example");
        // Display the Stage
        stage.show();
    }

    // Method to display the Season, which has been changed
    public void seasonChanged(ObservableValue<? extends String> observable, String oldValue, String newValue) {
        String oldText = oldValue == null ? "null" : oldValue.toString();
        String newText = newValue == null ? "null" : newValue.toString();

        logging.appendText("Season changed: old = " + oldText + ", new = " + newText + "\n");
    }

    // Method to display the Fruit, which has been changed
    public void fruitChanged(ObservableValue<? extends String> observable, String oldValue, String newValue) {
        String oldText = oldValue == null ? "null" : oldValue.toString();
        String newText = newValue == null ? "null" : newValue.toString();

        logging.appendText("Fruit changed: old = " + oldText + ", new = " + newText + "\n");
    }
}