import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class DemoCombo extends JFrame implements ItemListener
{
	JComboBox month;
	JLabel lbl1,lbl2;
	Container con;
	String selectitem;
	int selectindex;

	DemoCombo()
	{
		setTitle("COMBOBOX DEMO");

		con=getContentPane();
		con.setLayout(new FlowLayout(FlowLayout.LEFT));

		String mn_name[] = {"Jan","Feb","March","April","May","June","July","Aug","Sep","Oct","Nov","Dec"};

		month = new JComboBox();
		lbl1 = new JLabel("Nothing is Selected");
		lbl2 = new JLabel("Nothing is Selected");

		for(int i = 0; i<mn_name.length; i++)
		{
			month.addItem(mn_name[i]);
		}

		month.addItemListener(this);
		con.add(month);
		con.add(lbl1);
		con.add(lbl2);

		addWindowListener(new WindowAdapter()
		{
			public void windowClosing(WindowEvent we)
			{
				System.exit(0);
			}
		});

		setVisible(true);
		setSize(400,400);
	}//end of constructor	

	public void itemStateChanged(ItemEvent e)
	{
		lbl1.setText((String)month.getSelectedItem() + " is Selected\n");
		lbl2.setText("Item index is " + month.getSelectedIndex());
	}
	public static void main(String[] args) 
	{
		new DemoCombo();
	}
}