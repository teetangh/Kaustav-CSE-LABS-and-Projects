import java.util.ArrayList;
import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TextArea;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class FxListViewExample3 extends Application {
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
        Label personLbl = new Label("Select your Person: ");

        // Create the ListView
        ListView<Person> persons = new ListView<>();
        // Set the size of the ListView
        persons.setPrefSize(150, 120);
        // Add the Persons to the ListView
        persons.getItems().addAll(createPersonList());

        // Add a custom cell factory to display formatted names of persons
        persons.setCellFactory(new PersonCellFactory());

        // Update the message Label when the selected item changes
        persons.getSelectionModel().selectedItemProperty().addListener(new ChangeListener<Person>() {
            public void changed(ObservableValue<? extends Person> ov, final Person oldvalue, final Person newvalue) {
                personChanged(ov, oldvalue, newvalue);
            }
        });

        // Create the Selection HBox
        HBox selection = new HBox();
        // Set Spacing to 20 pixels
        selection.setSpacing(20);
        // Add the Label and Persons to the HBox
        selection.getChildren().addAll(personLbl, persons);

        // Create the VBox
        VBox root = new VBox();
        // Set Spacing to 10 pixels
        root.setSpacing(10);
        // Add the HBox and the TextArea to the VBox
        root.getChildren().addAll(selection, logging);

        // Set the Style-properties of the VBox
        root.setStyle("-fx-padding: 10;" + "-fx-border-style: solid inside;" + "-fx-border-width: 2;"
                + "-fx-border-insets: 5;" + "-fx-border-radius: 5;" + "-fx-border-color: blue;");

        // Create the Scene
        Scene scene = new Scene(root);
        // Add the Scene to the Stage
        stage.setScene(scene);
        // Set the Title
        stage.setTitle("A ListView Example with a Cell Factory");
        // Display the Stage
        stage.show();

    }

    // Helper-Method to create an ArrayList of Persons
    private ArrayList<Person> createPersonList() {
        ArrayList<Person> persons = new ArrayList<Person>();

        persons.add(new Person("Donna", "Duncan"));
        persons.add(new Person("Layne", "Estes"));
        persons.add(new Person("John", "Jacobs"));
        persons.add(new Person("Mason", "Boyd"));
        persons.add(new Person("Harry", "Eastwood"));

        return persons;
    }

    // Method to display the Person, which has been changed
    public void personChanged(ObservableValue<? extends Person> ov, Person oldValue, Person newValue) {
        String oldText = oldValue == null ? "null" : oldValue.toString();
        String newText = newValue == null ? "null" : newValue.toString();

        logging.appendText("Change: old = " + oldText + ", new = " + newText + "\n");
    }

}