import java.util.ArrayList;
import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.SelectionMode;
import javafx.scene.control.TextArea;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class FxListViewExample2 extends Application {
    // Declaring the TextArea for Logging
    TextArea logging;

    public static void main(String[] args) {
        Application.launch(args);
    }

    @Override
    public void start(Stage stage) {
        // Create the TextArea
        logging = new TextArea();
        logging.setMaxWidth(350);
        logging.setMaxHeight(350);

        // Create the Label
        Label monthsLbl = new Label("Select Month: ");

        // Create the ListView
        final ListView<String> months = new ListView<>();
        // Add the items to the List
        months.getItems().addAll(createMonthList());
        // Set the size of the ListView
        months.setPrefSize(120, 120);
        // Enable multiple selection
        months.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);

        // Update the message Label when the selected item changes
        months.getSelectionModel().selectedItemProperty().addListener(new ChangeListener<String>() {
            public void changed(ObservableValue<? extends String> ov, final String oldvalue, final String newvalue) {
                monthChanged(ov, oldvalue, newvalue);
            }
        });

        // Create the HBox for the Months
        HBox monthsSelection = new HBox();
        // Set Spacing to 10 pixels
        monthsSelection.setSpacing(10);
        // Add the Label and the List to the HBox
        monthsSelection.getChildren().addAll(monthsLbl, months);

        // Create some buttons to assist in selection
        Button selectAllBtn = new Button("Select All");
        Button clearAllBtn = new Button("Clear All");
        Button selectFirstBtn = new Button("Select First");
        Button selectLastBtn = new Button("Select Last");
        Button selectNextBtn = new Button("Select Next");
        Button selectPreviousBtn = new Button("Select Previous");

        // Let all buttons expand as needed
        selectAllBtn.setMaxWidth(Double.MAX_VALUE);
        clearAllBtn.setMaxWidth(Double.MAX_VALUE);
        selectFirstBtn.setMaxWidth(Double.MAX_VALUE);
        selectLastBtn.setMaxWidth(Double.MAX_VALUE);
        selectNextBtn.setMaxWidth(Double.MAX_VALUE);
        selectPreviousBtn.setMaxWidth(Double.MAX_VALUE);

        // Update the TextArea when all items will be selected
        selectAllBtn.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                months.getSelectionModel().selectAll();
            }
        });

        // Update the TextArea when the selection will be deleted
        clearAllBtn.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                months.getSelectionModel().clearSelection();
            }
        });

        // Update the TextArea when the first item will be selected
        selectFirstBtn.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                months.getSelectionModel().selectFirst();
            }
        });

        // Update the TextArea when the last item will be selected
        selectLastBtn.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                months.getSelectionModel().selectLast();
            }
        });

        // Update the TextArea when the next item will be selected
        selectNextBtn.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                months.getSelectionModel().selectNext();
            }
        });

        // Update the TextArea when the previous item will be selected
        selectPreviousBtn.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                months.getSelectionModel().selectPrevious();
            }
        });

        // Create the VBox for the Buttons
        VBox buttons = new VBox();
        // Add the Buttons to the VBox
        buttons.getChildren().addAll(selectFirstBtn, selectLastBtn, selectNextBtn, selectPreviousBtn, selectAllBtn,
                clearAllBtn);

        // Create the Selection HBox
        HBox selection = new HBox();
        // Set Spacing to 10 pixels
        selection.setSpacing(10);
        // Add the List and the Buttons to the HBox
        selection.getChildren().addAll(monthsSelection, buttons);

        // Create the GridPane
        GridPane pane = new GridPane();
        // Set the horizontal and vertical gaps between children
        pane.setHgap(10);
        pane.setVgap(5);
        // Add the HBox to the GridPane at position 0
        pane.addColumn(0, selection);
        // Add the Buttons to the GridPane at position 1
        pane.addColumn(1, buttons);

        // Create the VBox
        VBox root = new VBox();
        // Set Spacing to 10 pixels
        root.setSpacing(10);
        // Add the GridPane and the TextArea to the VBox
        root.getChildren().addAll(pane, logging);

        // Set the Style-properties of the VBox
        root.setStyle("-fx-padding: 10;" + "-fx-border-style: solid inside;" + "-fx-border-width: 2;"
                + "-fx-border-insets: 5;" + "-fx-border-radius: 5;" + "-fx-border-color: blue;");

        // Create the Scene
        Scene scene = new Scene(root);
        // Add the Scene to the Stage
        stage.setScene(scene);
        // Set the Title
        stage.setTitle("A ListView Example with a Selection Model");
        // Display the Stage
        stage.show();
    }

    // Helper-Method to create an ArrayList of Persons
    private ArrayList<String> createMonthList() {
        ArrayList<String> months = new ArrayList<String>();

        months.add("January");
        months.add("February");
        months.add("March");
        months.add("April");
        months.add("May");
        months.add("June");
        months.add("July");
        months.add("August");
        months.add("September");
        months.add("October");
        months.add("November");
        months.add("December");

        return months;
    }

    // Method to display the Data, which has been changed
    public void monthChanged(ObservableValue<? extends String> observable, String oldValue, String newValue) {
        String oldText = oldValue == null ? "null" : oldValue.toString();
        String newText = newValue == null ? "null" : newValue.toString();

        logging.appendText("Itemchanged: old = " + oldText + ", new = " + newText + "\n");
    }

}