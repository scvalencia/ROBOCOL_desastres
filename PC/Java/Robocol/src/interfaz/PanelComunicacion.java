package interfaz;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class PanelComunicacion extends JPanel implements ActionListener
{
	private static final long serialVersionUID=1L;
	private static final String NEW_LINE=System.getProperty("line.separator");

	private JTextArea displayAreaRecivo;
	private JTextField typingArea;
	private JTextArea displayAreaEnvio;

	public PanelComunicacion()
	{
		JButton button=new JButton("Clear");
		button.addActionListener(this);

		typingArea=new JTextField(30);

		displayAreaEnvio=new JTextArea();
		displayAreaEnvio.setEditable(false);
		displayAreaEnvio.setBackground(Color.BLACK);
		displayAreaEnvio.setForeground(Color.WHITE);
		JScrollPane scrollPaneenvio=new JScrollPane(displayAreaEnvio);
		scrollPaneenvio.setPreferredSize(new Dimension(425, 200));
		
		displayAreaRecivo=new JTextArea();
		displayAreaRecivo.setEditable(false);
		displayAreaRecivo.setBackground(Color.BLACK);
		displayAreaRecivo.setForeground(Color.GREEN);
		JScrollPane scrollPanerecivo=new JScrollPane(displayAreaRecivo);
		scrollPanerecivo.setPreferredSize(new Dimension(375, 200));

		setLayout(new BorderLayout());
		JPanel escribir=new JPanel();
		escribir.setLayout(new BorderLayout());
		escribir.add(typingArea, BorderLayout.CENTER);
		escribir.add(button, BorderLayout.EAST);
		add(escribir, BorderLayout.NORTH);
		
		JPanel contenedor=new JPanel();
		contenedor.setLayout(new GridLayout(1,2));
		contenedor.add(scrollPaneenvio);
		contenedor.add(scrollPanerecivo);
		add(contenedor, BorderLayout.CENTER);
	}

	/** Maneja el click del boton*/
	public void actionPerformed(ActionEvent e)
	{
		displayAreaRecivo.setText("");
		displayAreaEnvio.setText("");
		typingArea.setText("");

		typingArea.requestFocusInWindow();
	}

	public void displayInfoRecibida(String info)
	{
		displayAreaRecivo.append(info+NEW_LINE);
		displayAreaRecivo.setCaretPosition(displayAreaRecivo.getDocument().getLength());
	}

	public void displayInfoEnviada(String info)
	{
		displayAreaEnvio.append(info+NEW_LINE);
		displayAreaEnvio.setCaretPosition(displayAreaEnvio.getDocument().getLength());
	}
}