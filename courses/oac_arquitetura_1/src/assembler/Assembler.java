package assembler;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

import components.Register;

import architecture.Architecture;

public class Assembler {
	
	private ArrayList<String> lines;
	private ArrayList<String> objProgram;
	private ArrayList<String> execProgram;
	private Architecture arch;
	private ArrayList<String>commands;	
	private ArrayList<String>labels;
	private ArrayList<Integer> labelsAdresses;
	private ArrayList<String>variables;
	
	
	public Assembler() {
		lines = new ArrayList<>();
		labels = new ArrayList<>();
		labelsAdresses = new ArrayList<>();
		variables = new ArrayList<>();
		objProgram = new ArrayList<>();
		execProgram = new ArrayList<>();
		arch = new Architecture();
		commands = arch.getCommandsList();	
	}
	
	//getters
	
	public ArrayList<String> getObjProgram() {
		return objProgram;
	}
	
	/**
	 * These methods getters and set below are used only for TDD purposes
	 * @param lines
	 */
	
	protected ArrayList<String> getLabels() {
		return labels;
	}
	
	protected ArrayList<Integer> getLabelsAddresses() {
		return labelsAdresses;
	}
	
	protected ArrayList<String> getVariables() {
		return variables;
	}
	
	protected ArrayList<String> getExecProgram() {
		return execProgram;
	}
	
	protected void setLines(ArrayList<String> lines) {
		this.lines = lines;
	}	

	protected void setExecProgram(ArrayList<String> lines) {
		this.execProgram = lines;
	}	
	
	
	/*
	 * An assembly program is always in the following template
	 * <variables>
	 * <commands>
	 * Obs.
	 * 		variables names are always started with alphabetical char
	 * 	 	variables names must contains only alphabetical and numerical chars
	 *      variables names never uses any command name
	 * 		names ended with ":" identifies labels i.e. address in the memory
	 * 		Commands are only that ones known in the architecture. No comments allowed
	 * 	
	 * 		The assembly file must have the extention .dsf
	 * 		The executable file must have the extention .dxf 	
	 */
	


	/**
	 * This method reads an entire file in assembly 
	 * @param filename
	 * @throws IOException 
	 */
	public void read(String filename) throws IOException {
		   BufferedReader br = new BufferedReader(new		 
		   FileReader(filename+".dsf"));
		   String linha;
		   while ((linha = br.readLine()) != null) {
			     lines.add(linha);
			}
			br.close();
			
	}
	

	/**
	 * This method scans the strings in lines
	 * generating, for each one, the corresponding machine code
	 * @param lines
	 */
	public void parse() {
		for (String s : lines) {
			s = s.trim(); // Remove leading and trailing whitespace
			if (s.startsWith("#")) // this is a comment
				continue;

			String tokens[] = s.split("\\s+"); // Split using spaces and tabs as delimiters

			if (findCommandNumber(tokens) >= 0) { // the line is a command
				proccessCommand(tokens);
			} else { // the line is not a command: so, it can be a variable or a label
				if (tokens[0].endsWith(":")) { // if it ends with : it is a label
					String label = tokens[0].substring(0, tokens[0].length() - 1); // removing the last character
					labels.add(label);
					labelsAdresses.add(objProgram.size());
				} else // otherwise, it must be a variable
					variables.add(tokens[0]);
			}
		}
	}

	/**
	 * This method processes a command, putting it and its params (if they have)
	 * into the final array
	 * @param tokens
	 */
	protected void proccessCommand(String[] tokens) {
		// String command = tokens[0];
		String param ="";
		String param2 = "";
		String param3 = "";

		int commandNumber = findCommandNumber(tokens);

		// add
		if (commandNumber == 0) { //  addRegReg command
			param = tokens[1];
			param2 = tokens[2]; // this is a flag to indicate that is a position in memory 
		}
		else if (commandNumber == 1) { // addMemReg command
			param = "&"+tokens[1];
			param2 = tokens[2];        
		}
		else if (commandNumber == 2) { // addRegMem command
			param = tokens[1];
			param2 = "&"+tokens[2];
		}

		// sub
		else if (commandNumber == 3) { // subRegReg command
			param = tokens[1];
			param2 = tokens[2];
		}
		else if (commandNumber == 4) { // subMemReg command
			param = "&"+tokens[1];
			param2 = tokens[2];
		}
		else if (commandNumber == 5) { // subRegMem command
			param = tokens[1];
			param2 = "&"+tokens[2];
		}

		// move
		else if (commandNumber == 6) { // moveRegReg command
			param = tokens[1];
			param2 = tokens[2];
		}
		else if (commandNumber == 7) { // moveMemReg command
			param = "&"+tokens[1];
			param2 = tokens[2];
		}
		else if (commandNumber == 8) { // moveRegMem command
			param = tokens[1];
			param2 = "&"+tokens[2];
		}
		else if (commandNumber == 9) { // moveImmReg command
			param = tokens[1];
			param2 = tokens[2];
		}

		// inc
		else if (commandNumber == 10) { // incReg command
			param = tokens[1];
		}
		else if (commandNumber == 11) { // incMem command
			param = "&"+tokens[1];
		}

		// jmp
		else if (commandNumber == 12) { // jmpMem command
			param = "&"+tokens[1];
		}

		// jn
		else if (commandNumber == 13) { // jnMem command
			param = "&"+tokens[1];
		}

		// jz
		else if (commandNumber == 14) { // jzMem command
			param = "&"+tokens[1];
		}

		// jnz
		else if (commandNumber == 15) { // jnzMem command
			param = "&"+tokens[1];
		}

		// jeq
		else if (commandNumber == 16) { // jeqRegRegMem command
			param = tokens[1];
			param2 = tokens[2];
			param3 = "&"+tokens[3];
		}

		// jgt
		else if (commandNumber == 17) { // jgtRegRegMem command
			param = tokens[1];
			param2 = tokens[2];
			param3 = "&"+tokens[3];
		}

		// jlw
		else if (commandNumber == 18) { // jlwRegRegMem command
			param = tokens[1];
			param2 = tokens[2];
			param3 = "&"+tokens[3];
		}

		// call
		else if (commandNumber == 19) { // callMem command
			param = "&"+tokens[1];
		}

		// ret
		else if (commandNumber == 20) { // ret command
			// nothing to do
		}
		
		objProgram.add(Integer.toString(commandNumber));

		if (!param.isEmpty()) {
			objProgram.add(param);
			if (!param2.isEmpty()) {
				objProgram.add(param2);
				if (!param3.isEmpty()) {
					objProgram.add(param3);
				}
			}
		}
	}
	

	/**
	 * This method searches for the command number in the commands list
	 * @param tokens
	 * @return
	 */
	private int findCommandNumber(String[] tokens) {
		int p = commands.indexOf(tokens[0]);

		if (p < 0) //the command isn't in the list. So it must have multiple formats
		{ 
			if ("add".equals(tokens[0])) //the command is a add
				p = proccessAdd(tokens);

			else if ("sub".equals(tokens[0])) //the command is a sub
				p = proccessSub(tokens);

			else if ("move".equals(tokens[0])) //the command is a move
				p = proccessMove(tokens);

			else if ("inc".equals(tokens[0])) //the command is a inc
				p = proccessInc(tokens);

			else if ("jmp".equals(tokens[0])) //the command is a jmp
				p = commands.indexOf("jmpMem");
			
			else if ("jn".equals(tokens[0])) //the command is a jn
				p = commands.indexOf("jnMem");

			else if ("jz".equals(tokens[0])) //the command is a jz
				p = commands.indexOf("jzMem");
			
			else if ("jnz".equals(tokens[0])) //the command is a jnz
				p = commands.indexOf("jnzMem");
			
			else if ("jeq".equals(tokens[0])) //the command is a jeq
				p = commands.indexOf("jeqRegRegMem");
			
			else if ("jgt".equals(tokens[0])) //the command is a jgt
				p = commands.indexOf("jgtRegRegMem");
			
			else if ("jlw".equals(tokens[0])) //the command is a jlw
				p = commands.indexOf("jlwRegRegMem");
			
			else if ("call".equals(tokens[0])) //the command is a call
				p = commands.indexOf("callMem");
			
			else if ("ret".equals(tokens[0])) //the command is a ret
				p = commands.indexOf("ret");

		}
		return p;
	}


	/**
	 * This method processes a add command, searching for the format
	 * @param tokens
	 * @return
	 */
	private int proccessAdd(String[] tokens) {
		String p1 = tokens[1];
		String p2 = tokens[2];
		int p = -1;

		if (p1.startsWith("%") && p2.startsWith("%"))  //this is a addRegReg
			p = commands.indexOf("addRegReg");
		
		else if (p1.startsWith("%") && p2.matches("[A-Za-z]+"))  //this is a addRegMem
			p = commands.indexOf("addRegMem");
		
		else if (p1.matches("[A-Za-z]+") && p2.startsWith("%"))  //this is a addMemReg
			p = commands.indexOf("addMemReg");
		
		return p;
	}

	/**
	 * This method processes a sub command, searching for the format
	 * @param tokens
	 * @return
	 */
	private int proccessSub(String[] tokens) {
		String p1 = tokens[1];
		String p2 = tokens[2];
		int p = -1;

		if (p1.startsWith("%") && p2.startsWith("%"))  //this is a subRegReg
			p = commands.indexOf("subRegReg");

		else if (p1.matches("[A-Za-z]+") && p2.startsWith("%"))  //this is a subMemReg
			p = commands.indexOf("subMemReg");
		
		else if (p1.startsWith("%") && p2.matches("[A-Za-z]+"))  //this is a subRegMem
			p = commands.indexOf("subRegMem");
		
		return p;
	}

	/**
	 * This method processes a move command, searching for the format
	 * @param tokens
	 * @return
	 */
	private int proccessMove(String[] tokens) {
		String p1 = tokens[1];
		String p2 = tokens[2];
		int p = -1;

		if (p1.startsWith("%") && p2.startsWith("%"))  //this is a moveRegReg
			p = commands.indexOf("moveRegReg");
		
		else if (p1.matches("[A-Za-z]+") && p2.startsWith("%"))  //this is a moveMemReg
			p = commands.indexOf("moveMemReg");
		
		else if (p1.startsWith("%") && p2.matches("[A-Za-z]+"))  //this is a moveRegMem
			p = commands.indexOf("moveRegMem");
		
		else if (p1.matches("[-]*[0-9]+") && p2.startsWith("%"))  //this is a moveImmReg
			p = commands.indexOf("moveImmReg");
		
		
		return p;
	}

	/**
	 * This method processes a inc command, searching for the format
	 * @param tokens
	 * @return
	 */
	private int proccessInc(String[] tokens) {
		String p1 = tokens[1];
		int p = -1;

		if (p1.startsWith("%"))  //this is a incReg
			p = commands.indexOf("incReg");
		
		else if (p1.matches("[A-Za-z]+"))  //this is a incMem
			p = commands.indexOf("incMem");
		
		return p;
	}

	/**
	 * This method creates the executable program from the object program
	 * Step 1: check if all variables and labels mentioned in the object 
	 * program are declared in the source program
	 * Step 2: allocate memory addresses (space), from the end to the begin (stack)
	 * to store variables
	 * Step 3: identify memory positions to the labels
	 * Step 4: make the executable by replacing the labels and the variables by the
	 * corresponding memory addresses 
	 * @param filename 
	 * @throws IOException 
	 */
	public void makeExecutable(String filename) throws IOException {
		if (!checkLabels())
			return;

		execProgram = (ArrayList<String>) objProgram.clone();
		replaceAllVariables();
		replaceLabels(); //replacing all labels by the address they refer to
		replaceRegisters(); //replacing all registers by the register id they refer to
		saveExecFile(filename);
		System.out.println("Finished");
	}

	/**
	 * This method replaces all the registers names by its correspondings ids.
	 * registers names must be prefixed by %
	 */
	protected void replaceRegisters() {
		int p=0;
		for (String line:execProgram) {
			if (line.startsWith("%")){ //this line is a register
				line = line.substring(1, line.length());
				int regId = searchRegisterId(line, arch.getRegistersList());
				String newLine = Integer.toString(regId);
				execProgram.set(p, newLine);
			}
			p++;
		}
		
	}

	/**
	 * This method replaces all variables by their addresses.
	 * The addresses o0f the variables startes in the end of the memory
	 * and decreases (creating a stack)
	 */
	protected void replaceAllVariables() {
		// Starting from the end of the memory
		int position = arch.getMemorySize() - arch.getStackSize()+1;
		
		for (String var : this.variables) { // Scanning all variables
			replaceVariable(var, position);
			position --;
		}
	}

	/**
	 * This method saves the execFile collection into the output file
	 * @param filename
	 * @throws IOException 
	 */
	private void saveExecFile(String filename) throws IOException {
		File file = new File(filename+".dxf");
		BufferedWriter writer = new BufferedWriter(new FileWriter(file));
		for (String l : execProgram)
			writer.write(l+"\n");
		writer.write("-1"); //-1 is a flag indicating that the program is finished
		writer.close();
		
	}

	/**
	 * This method replaces all labels in the execprogram by the corresponding
	 * address they refer to
	 */
	protected void replaceLabels() {
		int i = 0;
		for (String label : labels) { //searching all labels
			label = "&"+label;
			int labelPointTo = labelsAdresses.get(i);
			int lineNumber = 0;
			for (String l : execProgram) {
				if (l.equals(label)) {//this label must be replaced by the address
					String newLine = Integer.toString(labelPointTo); // the address
					execProgram.set(lineNumber, newLine);
				}
				lineNumber++;
			}
			i++;
		}
		
	}

	/**
	 * This method replaces all occurences of a variable
	 * name found in the object program by his address
	 * in the executable program
	 * @param var
	 * @param position
	 */
	protected void replaceVariable(String var, int position) {
		var = "&"+var;
		int i = 0;
		for (String s:execProgram) {
			if (s.equals(var)) {
				s = Integer.toString(position);
				execProgram.set(i, s);
			}
			i++;
		}
	}

	/**
	 * This method checks if all labels and variables in the object program were in the source
	 * program.
	 * The labels and the variables collection are used for this
	 */
	protected boolean checkLabels() {
		System.out.println("Checking labels and variables");
		for (String line:objProgram) {
			boolean found = false;
			if (line.startsWith("&")) { //if starts with "&", it is a label or a variable
				line = line.substring(1, line.length());
				if (labels.contains(line))
					found = true;
				if (variables.contains(line))
					found = true;
				if (!found) {
					System.out.println("FATAL ERROR! Variable or label "+line+" not declared!");
					return false;
				}
			}
		}
		return true;
	}
	
	/**
	 * This method searches for a register in the architecture register list
	 * by the register name
	 * @param line
	 * @param registersList
	 * @return
	 */
	private int searchRegisterId(String line, ArrayList<Register> registersList) {
		int i=0;
		for (Register r:registersList) {
			if (line.equals(r.getRegisterName())) {
				return i;
			}
			i++;
		}
		return -1;
	}

	public static void main(String[] args) throws IOException {
		String filename = "program2";
		Assembler assembler = new Assembler();
		System.out.println("Reading source assembler file: "+filename+".dsf");
		assembler.read(filename);
		System.out.println("Generating the object program");
		assembler.parse();
		System.out.println("Generating executable: "+filename+".dxf");
		assembler.makeExecutable(filename);
	}
		
}
