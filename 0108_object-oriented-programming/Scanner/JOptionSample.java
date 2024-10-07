import javax.swing.JOptionPane;

public class JOptionSample{
	public static void main(String args[]){
		
	String name = "";

	name = JOptionPane.showInputDialog("Please Enter Your Name ");

	String msg = "Your name is " + name;

	JOptionPane.showMessageDialog(null, msg);
}

}