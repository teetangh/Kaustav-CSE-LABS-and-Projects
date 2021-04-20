package application;
import java.sql.*;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

public class DeptController {

    @FXML
    private TextField txtId;

    @FXML
    private TextField txtName;

    @FXML
    private Button btnNext;

    @FXML
    private Button btnId;

    @FXML
    void onShow() {

try {
	Class.forName("oracle.jdbc.driver.OracleDriver"); // for server IP address instead of localhost 
	Connection con;
	//Database connection
	con = DriverManager.getConnection(  "jdbc:oracle:thin:@172.:1521:XE","system","admin");
	String SQL = "SELECT dept_name from Department where deptName=" + txtId.getText();// where id=10101";
	ResultSet rs = con.createStatement().executeQuery(SQL);
	if(rs.next()) {
		txtName.setText(rs.getString(1));
	}
} catch (Exception e) {
	// TODO Auto-generated catch block
	e.printStackTrace();
} 
    }

    @FXML
    void d71b1b() {

    }

    @FXML
    void onNext() {

    }

    @FXML
    void c41010() {

    }

}
