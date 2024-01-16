package architecture;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

import components.Bus;
import components.Demux;
import components.Memory;
import components.Register;
import components.Ula;

public class Architecture {

	private boolean simulation; // this boolean indicates if the execution is done in simulation mode.
								// simulation mode shows the components' status after each instruction

	private boolean halt;
	private Bus extbus1;
	private Bus intbus1;
	private Bus intbus2;
	private Memory memory;
	private Memory statusMemory;
	private int stackSize;
	private int memorySize;
	private Register PC;
	private Register IR;
	private Register RPG0;
	private Register RPG1;
	private Register RPG2;
	private Register RPG3;
	private Register Flags;
	private Register stackBottom;
	private Register stackTop;
	private Ula ula;
	private Demux demux; // only for multiple register purposes

	private ArrayList<String> commandsList;
	private ArrayList<Register> registersList;

	/**
	 * Instanciates all components in this architecture
	 */
	private void componentsInstances() {
		// don't forget the instantiation order
		// buses -> registers -> ula -> memory
		extbus1 = new Bus();
		intbus1 = new Bus();
		intbus2 = new Bus();

		PC = new Register("PC", extbus1, intbus2);
		IR = new Register("IR", extbus1, intbus2);
		RPG0 = new Register("RPG0", extbus1, intbus1);
		RPG1 = new Register("RPG1", extbus1, intbus1);
		RPG2 = new Register("RPG2", extbus1, intbus1);
		RPG3 = new Register("RPG3", extbus1, intbus1);
		Flags = new Register(2, intbus2);

		stackBottom = new Register("stackBottom", intbus2, intbus2);
		stackTop = new Register("stackTop", intbus2, intbus2);
		fillRegistersList();

		ula = new Ula(intbus1, intbus2);

		// 28 dos 128 endereços de memória são reservados para a pilha
		stackSize = 28;
		memorySize = 128;
		memory = new Memory(memorySize, extbus1);
		statusMemory = new Memory(2, extbus1);
		demux = new Demux();
		
		fillCommandsList();
		setStackPointers(); // Set the stack pointers to the bottom of the stack
	}

	/**
	 * This method fills the registers list inserting into them all the registers we
	 * have.
	 * IMPORTANT!
	 * The first register to be inserted must be the default RPG
	 */
	private void fillRegistersList() {
		registersList = new ArrayList<Register>();
		registersList.add(RPG0);
		registersList.add(RPG1);
		registersList.add(RPG2);
		registersList.add(RPG3);
		registersList.add(PC);
		registersList.add(IR);
		registersList.add(Flags);
		registersList.add(stackBottom);
		registersList.add(stackTop);
	}

	private void setStackPointers() {
			intbus2.put(101);
			stackTop.store();
			stackBottom.store();
	}

	/**
	 * Constructor that instanciates all components according the architecture
	 * diagram
	 */
	public Architecture() {
		componentsInstances();

		// by default, the execution method is never simulation mode
		simulation = false;
	}

	public Architecture(boolean sim) {
		componentsInstances();

		// in this constructor we can set the simoualtion mode on or off
		simulation = sim;
	}

	// getters

	protected Bus getExtbus1() {
		return extbus1;
	}

	protected Bus getIntbus1() {
		return intbus1;
	}

	protected Bus getIntbus2() {
		return intbus2;
	}

	protected Memory getMemory() {
		return memory;
	}

	protected Register getPC() {
		return PC;
	}

	protected Register getIR() {
		return IR;
	}

	protected Register getRPG(int which_rpg) {
		switch (which_rpg) {
			case 0:
				return RPG0;
			case 1:
				return RPG1;
			case 2:
				return RPG2;
			case 3:
				return RPG3;
			default:
				return RPG0;
		}
	}

	protected Register getStackBottom() {
		return stackBottom;
	}

	protected Register getStackTop() {
		return stackTop;
	}

	protected Register getFlags() {
		return Flags;
	}

	protected Ula getUla() {
		return ula;
	}

	public ArrayList<String> getCommandsList() {
		return commandsList;
	}

	protected Demux getDemux() {
		return demux;
	}

	public ArrayList<Register> getRegistersList() {
		return registersList;
	}

	public int getStackSize() {
		return stackSize;
	}

	// all the microprograms must be impemented here
	// the instructions table is
	/*
	 * add %<regA> %<regB> || RegB <- RegA + RegB
	 * add <mem> %<regA> || RegA <- memória[mem] + RegA
	 * add %<regA> <mem> || Memória[mem] <- RegA + memória[mem]
	 * sub <regA> <regB> || RegB <- RegA - RegB
	 * sub <mem> %<regA> || RegA <- memória[mem] - RegA
	 * sub %<regA> <mem> || memória[mem] <- RegA - memória[mem]
	 * move <mem> %<regA> || RegA <- memória[mem]
	 * move %<regA> <mem> || memória[mem] <- RegA
	 * move %<regA> %<regB> || RegB <- RegA
	 * move imm %<regA> || RegA <- immediate
	 * inc %<regA> || RegA ++
	 * inc <mem> || memória[mem] ++
	 * jmp <mem> || PC <- mem (desvio incondicional)
	 * jn <mem> || se última operação<0 então PC <- mem (desvio condicional)
	 * jz <mem> || se última operação=0 então PC <- mem (desvio condicional)
	 * jnz <mem> || se última operação|=0 então PC <- mem (desvio condicional)
	 * jeq %<regA> %<regB> <mem> || se RegA==RegB então PC <- mem (desvio
	 * condicional)
	 * jgt %<regA> %<regB> <mem> || se RegA>RegB então PC <- mem (desvio
	 * condicional)
	 * jlw %<regA> %<regB> <mem> || se RegA<RegB então PC <- mem (desvio
	 * condicional)
	 * call <mem> || PC <- mem ((desvio incondicional) mas, antes de desviar,empilha
	 * o endereço de retorno (endereço da instrução imediatamente posterior ao
	 * callMem (push(PC++) )
	 * ret || PC <- pop() (desvio incondicional)
	 */

	/**
	 * This method fills the commands list arraylist with all commands used in this
	 * architecture
	 */
	protected void fillCommandsList() {
		commandsList = new ArrayList<String>();
		commandsList.add("addRegReg"); // 0
		commandsList.add("addMemReg"); // 1
		commandsList.add("addRegMem"); // 2
		commandsList.add("subRegReg"); // 3
		commandsList.add("subMemReg"); // 4
		commandsList.add("subRegMem"); // 5
		commandsList.add("moveRegReg"); // 6
		commandsList.add("moveMemReg"); // 7
		commandsList.add("moveRegMem"); // 8
		commandsList.add("moveImmReg"); // 9
		commandsList.add("incReg"); // 10
		commandsList.add("incMem"); // 11
		commandsList.add("jmpMem"); // 12
		commandsList.add("jnMem"); // 13
		commandsList.add("jzMem"); // 14
		commandsList.add("jnzMem"); // 15
		commandsList.add("jeqRegRegMem"); // 16
		commandsList.add("jgtRegRegMem"); // 17
		commandsList.add("jlwRegRegMem"); // 18
		commandsList.add("callMem"); // 19
		commandsList.add("ret"); // 20
	}

	/**
	 * This method is used after some ULA operations, setting the flags bits
	 * according the result.
	 * 
	 * @param result is the result of the operation
	 *               NOT TESTED!!!!!!!
	 */
	private void setStatusFlags(int result) {
		Flags.setBit(0, 0);
		Flags.setBit(1, 0);
		if (result == 0) { // bit 0 in flags must be 1 in this case
			Flags.setBit(0, 1);
		}
		if (result < 0) { // bit 1 in flags must be 1 in this case
			Flags.setBit(1, 1);
		}
	}
	
	//////////////////////////////////// MICROPROGRAMAS /////////////////////////////////////

	public void addRegReg() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Pegando o valor de um RPG e colocando na ULA
		PC.read();
		memory.read();
		demux.setValue(extbus1.get());
		registersInternalRead();
		ula.store(0);

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Pegando o valor de um RPG e colocando na ULA
		PC.read();
		memory.read();
		demux.setValue(extbus1.get());
		registersInternalRead();
		ula.store(1);

		// Somando na ULA e guardando num RPG
		ula.add();
		ula.read(1);
		setStatusFlags(intbus1.get());
		registersInternalStore();

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
	};

	public void addMemReg() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Pegando o valor da memória e colocando no registrador IR
		PC.read();
		memory.read();
		memory.read();
		IR.store();

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Pegando o valor de um RPG e colocando na ULA
		PC.read();
		memory.read();
		demux.setValue(extbus1.get());
		registersInternalRead();
		ula.store(0);

		// Pegando o valor de IR, somando na ULA e guardando num RPG
		IR.internalRead();
		ula.internalStore(1);
		ula.add();
		ula.read(1);
		ula.internalRead(1);
		setStatusFlags(intbus2.get());
		registersInternalStore();

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
	};

	public void addRegMem() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		PC.read();
		memory.read();
		memory.read();
		IR.store();
		IR.internalRead();
		ula.internalStore(0);

		// PC++
		PC.internalRead(); 
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		PC.read();
		memory.read();
		demux.setValue(extbus1.get());
		registersInternalRead();
		ula.store(1);
		ula.add();
		ula.internalRead(1);
		setStatusFlags(intbus2.get());
	
		IR.internalStore();
		IR.read();
		memory.store();
		memory.store();

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore(); 
	};

	public void subRegReg() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Pegando o valor de um RPG e colocando na ULA
		PC.read();
		memory.read();
		demux.setValue(extbus1.get());
		registersInternalRead();
		ula.store(0);

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Pegando o valor de um RPG e colocando na ULA
		PC.read();
		memory.read();
		demux.setValue(extbus1.get());
		registersInternalRead();
		ula.store(1);

		// Subtraindo na ULA e guardando num RPG
		ula.sub();
		ula.read(1);
		ula.internalRead(1);
		setStatusFlags(intbus2.get());
		registersInternalStore();

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
	};

	public void subMemReg() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Pegando o valor da memória e colocando no registrador IR
		PC.read();
		memory.read();
		memory.read();
		IR.store();

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Pegando o valor de um RPG e colocando na ULA
		PC.read();
		memory.read();
		demux.setValue(extbus1.get());
		registersInternalRead();
		ula.store(0);

		// Pegando o valor de IR, subtraindo na ULA e guardando num RPG
		IR.internalRead();
		ula.internalStore(1);
		ula.sub();
		ula.read(1);
		ula.internalRead(1);
		setStatusFlags(intbus2.get());
		registersInternalStore();

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
	};

	public void subRegMem() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		PC.read();
		memory.read();
		memory.read();
		IR.store();
		IR.internalRead();
		ula.internalStore(0);

		// PC++
		PC.internalRead(); 
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		PC.read();
		memory.read();
		demux.setValue(extbus1.get());
		registersInternalRead();
		ula.store(1);
		ula.sub();
		ula.internalRead(1);
		setStatusFlags(intbus2.get());
	
		IR.internalStore();
		IR.read();
		memory.store();
		memory.store();

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore(); 
	};

	public void moveRegReg() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Fazendo a memória colocar na barramento qual registrador deve mandar o dado.
		PC.read();
		memory.read();
		demux.setValue( extbus1.get() );
		registersRead();
		IR.store();

		// Fazendo PC apontar para o endereço do registrador que vai receber o dado.
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		PC.read();
		memory.read();
		demux.setValue( extbus1.get() );
		IR.read();
		registersStore();

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
	};

	public void moveMemReg() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore(); 

		PC.read();
		memory.read();
		memory.read();
		IR.store();

		// Fazendo PC apontar para o endereço de memória que está o REG.
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Fazendo a memória colocar no barramento o endereço do REG
		PC.read();
		memory.read();
		demux.setValue( extbus1.get() ); 
		IR.read();
		registersStore();

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
	};

	public void moveRegMem() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Enviando pro barramento qual registrador deve mandar o dado.
		PC.read();
		memory.read();
		demux.setValue( extbus1.get() );
		registersRead();
		IR.store();

		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Enviando pro barramento o endereço que devemos armazenar o dado.
		PC.read();
		memory.read();
		memory.store();
		IR.read();
		memory.store();

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
	};

	public void moveImmReg() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Enviando pro barramento o dado que é para ser colocado no registrador.
		PC.read();
		memory.read();
		IR.store();

		// Fazendo PC apontar para o endereço do Registrador.
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Fazendo a memória devolver o Registrador para armazenar o dado
		PC.read();
		memory.read();
		demux.setValue( extbus1.get() );
		IR.read();
		registersStore();

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
	};

	public void incReg() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
		
		PC.read();
		memory.read();

		demux.setValue(extbus1.get());
		registersInternalRead();
		ula.store(1);
		ula.inc();
		ula.read(1);
		ula.internalRead(1);
		setStatusFlags(intbus2.get());
		registersInternalStore();

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore(); 
	};

	public void incMem() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
		
		PC.read();
		memory.read();
		memory.read();

		// Incrementando o valor de IR na ULA
		IR.store();
		IR.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		setStatusFlags(intbus2.get());

		IR.internalStore();
		IR.read();
		memory.store();
		memory.store();
		
		// PC++
		PC.internalRead(); 
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
	};

	public void jmpMem() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
		
		PC.read();
		memory.read();
		PC.store();
	};

	public void jnMem() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
		
		PC.read();
		memory.read();
		
		statusMemory.storeIn1();
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
		PC.read();
		statusMemory.storeIn0(); 
		extbus1.put(Flags.getBit(1)); 
		statusMemory.read(); 
		PC.store(); 
	};

	public void jzMem() {
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
		
		PC.read();
		memory.read();
		
		statusMemory.storeIn1();
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
		PC.read();
		statusMemory.storeIn0(); 
		extbus1.put(Flags.getBit(0)); 
		statusMemory.read(); 
		PC.store(); 
	};

	public void jnzMem() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();	
		
		PC.read();
		memory.read();
		
		statusMemory.storeIn0();
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
		PC.read();
		statusMemory.storeIn1(); 
		extbus1.put(Flags.getBit(0)); 
		statusMemory.read(); 
		PC.store(); 
	};

	public void jeqRegRegMem() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Passando o dado do RegA pro barramento e guarda na ula(0)
		PC.read();
		memory.read();
		demux.setValue(extbus1.get());
		registersInternalRead();
		ula.store(0);

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Passando o dado do RegB pro barramento e guarda na ula(1).
		PC.read();
		memory.read();
		demux.setValue(extbus1.get());
		registersInternalRead();
		ula.store(1);

		// Subtraindo e mudando o status Flag
		ula.sub();
		ula.internalRead(1);
		setStatusFlags(intbus2.get());

		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
		
		PC.read();
		memory.read();
		
		statusMemory.storeIn1();
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
		PC.read();
		statusMemory.storeIn0(); 
		extbus1.put(Flags.getBit(1)); 
		statusMemory.read(); 
		PC.store(); 
		
	};

	/* MAIOR
	   RPG - RPG = POSITIVO
	 * 0: 0 ; SE É ZERO
	 * 1: 0 ; SE É NEGATIVO
	 * 
	 * MENOR
	 * RPG - RPG = NEGATIVO
	 * 0: 0 ; SE É ZERO
	 * 1: 1 ; SE É NEGATIVO
	 */
	public void jgtRegRegMem() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Passando o dado do RegA pro barramento e guarda na ula(0)
		PC.read();
		memory.read();
		demux.setValue(extbus1.get());
		registersInternalRead();
		ula.store(0);

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Passando o dado do RegB pro barramento e guarda na ula(1).
		PC.read();
		memory.read();
		demux.setValue(extbus1.get());
		registersInternalRead();
		ula.store(1);

		// Subtraindo e mudando o status Flag
		ula.sub();
		ula.internalRead(1);
		setStatusFlags(intbus2.get());

		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
		
		PC.read();
		memory.read();
		
		statusMemory.storeIn0();
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
		PC.read();
		statusMemory.storeIn1(); 

		extbus1.put(Flags.getBit(0));
		IR.read();
		IR.internalStore();
		ula.internalStore(0);

		extbus1.put(Flags.getBit(1));
		IR.read();
		IR.internalStore();
		ula.internalStore(1);

		ula.add();
		ula.internalRead(1);
		setStatusFlags(intbus2.get());
		
		extbus1.put(Flags.getBit(1));

		statusMemory.read(); 
		PC.store();
	};

	public void jlwRegRegMem() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Passando o dado do RegA pro barramento e guarda na ula(0)
		PC.read();
		memory.read();
		demux.setValue(extbus1.get());
		registersInternalRead();
		ula.store(0);

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Passando o dado do RegB pro barramento e guarda na ula(1).
		PC.read();
		memory.read();
		demux.setValue(extbus1.get());
		registersInternalRead();
		ula.store(1);

		// Subtraindo e mudando o status Flag
		ula.sub();
		ula.internalRead(1);
		setStatusFlags(intbus2.get());

		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
		
		PC.read();
		memory.read();
		
		statusMemory.storeIn1();
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();
		PC.read();
		statusMemory.storeIn0(); 
		extbus1.put(Flags.getBit(1)); 
		statusMemory.read(); 
		PC.store();
	};

	public void callMem() {
		// PC++
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		PC.internalStore();

		// Preparando memória para armazenar o endereço de retorno
		stackTop.internalRead();
		IR.internalStore();
		IR.read();
		memory.store();

		// Armazenando o endereço de retorno na posição stackTop
		PC.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		IR.internalStore();
		IR.read();
		memory.store();

		// stackTop++
		stackTop.internalRead();
		ula.internalStore(1);
		ula.inc();
		ula.internalRead(1);
		stackTop.internalStore();

		PC.read();
		memory.read();
		PC.store();
	};

	public void ret() {
		// Verifica se a pilha está vazia (stackTop == stackBottom)
		stackBottom.internalRead();
		ula.internalStore(0);
		stackTop.internalRead();
		ula.internalStore(1);
		ula.sub();
		ula.internalRead(1);
		setStatusFlags(intbus2.get());


		// Se stackBottom < stackTop então a pilha não está vazia
		if ( Flags.getBit(1) == 1 ) { 
			// stackTop--
			// ex. stackTop = 5 com ULA[reg0, reg1]
			stackTop.internalRead();
			ula.internalStore(1);
			ula.inc(); // ULA[reg0, 5].inc() -> ULA[reg0, 6]

			ula.internalStore(0);
			ula.sub(); // ULA[5, 6].sub() -> ULA[5, -1]
			ula.add(); // ULA[5, -1].add() -> ULA[5, 4]

			ula.internalRead(1);
			setStatusFlags(intbus2.get());
			stackTop.internalStore(); // = 4

			// PC recebe o endereço de retorno
			IR.internalStore();
			IR.read();
			memory.read();
			PC.store();
		}
		else {
			// PC++
			PC.internalRead();
			ula.internalStore(1);
			ula.inc();
			ula.internalRead(1);
			PC.internalStore();
		}
	};

	/////////////////////////////////////////////////////////////////////////////////////

	/**
	 * This method performs an (external) read from a register into the register
	 * list.
	 * The register id must be in the demux bus
	 */
	private void registersRead() {
		registersList.get(demux.getValue()).read();
	}

	/**
	 * This method performs an (internal) read from a register into the register
	 * list.
	 * The register id must be in the demux bus
	 */
	private void registersInternalRead() {
		registersList.get(demux.getValue()).internalRead();
		;
	}

	/**
	 * This method performs an (external) store toa register into the register list.
	 * The register id must be in the demux bus
	 */
	private void registersStore() {
		registersList.get(demux.getValue()).store();
	}

	/**
	 * This method performs an (internal) store toa register into the register list.
	 * The register id must be in the demux bus
	 */
	private void registersInternalStore() {
		registersList.get(demux.getValue()).internalStore();
	}

	/**
	 * This method reads an entire file in machine code and
	 * stores it into the memory
	 * NOT TESTED
	 * 
	 * @param filename
	 * @throws IOException
	 */
	public void readExec(String filename) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(filename + ".dxf"));
		String linha;

		int i = 0;
		while ((linha = br.readLine()) != null) {
			extbus1.put(i);
			memory.store();
			extbus1.put(Integer.parseInt(linha));
			memory.store();
			i++;
		}
		br.close();
	}

	/**
	 * This method executes a program that is stored in the memory
	 */
	public void controlUnitEexec() {
		halt = false;
		while (!halt) {
			fetch();
			decodeExecute();
		}

	}

	/**
	 * This method implements The decode proccess,
	 * that is to find the correct operation do be executed
	 * according the command.
	 * And the execute proccess, that is the execution itself of the command
	 */
	private void decodeExecute() {
		IR.internalRead(); // the instruction is in the internalbus2
		int command = intbus2.get();
		simulationDecodeExecuteBefore(command);
		switch (command) {
			case 0: {
				addRegReg();
				break;
			}
			case 1: {
				addMemReg();
				break;
			}
			case 2: {
				addRegMem();
				break;
			}
			case 3: {
				subRegReg();
				break;
			}
			case 4: {
				subMemReg();
				break;
			}
			case 5: {
				subRegMem();
				break;
			}
			case 6: {
				moveRegReg();
				break;
			}
			case 7: {
				moveMemReg();
				break;
			}
			case 8: {
				moveRegMem();
				break;
			}
			case 9: {
				moveImmReg();
				break;
			}
			case 10: {
				incReg();
				break;
			}
			case 11: {
				incMem();
				break;
			}
			case 12: {
				jmpMem();
				break;
			}
			case 13: {
				jnMem();
				break;
			}
			case 14: {
				jzMem();
				break;
			}
			case 15: {
				jnzMem();
				break;
			}
			case 16: {
				jeqRegRegMem();
				break;
			}
			case 17: {
				jgtRegRegMem();
				break;
			}
			case 18: {
				jlwRegRegMem();
				break;
			}
			case 19: {
				callMem();
				break;
			}
			case 20: {
				ret();
				break;
			}
			default: {
				halt = true;
				break;
			}
		}
		if (simulation)
			simulationDecodeExecuteAfter();
	}

	/**
	 * This method is used to show the components status in simulation conditions
	 * NOT TESTED
	 * 
	 * @param command
	 */
	private void simulationDecodeExecuteBefore(int command) {
		System.out.println("----------BEFORE Decode and Execute phases--------------");
		String instruction;
		int parameter = 0;

		for (Register r : registersList) {
			System.out.println(r.getRegisterName() + ": " + r.getData());
		}

		if (command != -1) instruction = commandsList.get(command);
		else instruction = "END";

		if (hasOperands(instruction)) {
			parameter = memory.getDataList()[PC.getData() + 1];
			System.out.println("Instruction: " + instruction + " " + parameter);
		}
		else
			System.out.println("Instruction: " + instruction);

		if ("read".equals(instruction))
			System.out.println("memory[" + parameter + "]=" + memory.getDataList()[parameter]);

	}

	/**
	 * This method is used to show the components status in simulation conditions
	 * NOT TESTED
	 */
	private void simulationDecodeExecuteAfter() {
		String instruction;
		System.out.println("-----------AFTER Decode and Execute phases--------------");
		System.out.println("Internal Bus 1: " + intbus1.get());
		System.out.println("Internal Bus 2: " + intbus2.get());
		System.out.println("External Bus 1: " + extbus1.get());
		for (Register r : registersList) {
			System.out.println(r.getRegisterName() + ": " + r.getData());
		}
		Scanner entrada = new Scanner(System.in);
		System.out.println("Press <Enter>");
		String mensagem = entrada.nextLine();
	}

	/**
	 * This method uses PC to find, in the memory,
	 * the command code that must be executed.
	 * This command must be stored in IR
	 * NOT TESTED!
	 */
	private void fetch() {
		PC.read();
		memory.read();
		IR.store();
		simulationFetch();
	}

	/**
	 * This method is used to show the components status in simulation conditions
	 * NOT TESTED!!!!!!!!!
	 */
	private void simulationFetch() {
		if (simulation) {
			System.out.println("-------Fetch Phase------");
			System.out.println("PC: " + PC.getData());
			System.out.println("IR: " + IR.getData());
		}
	}

	/**
	 * This method is used to show in a correct way the operands (if there is any)
	 * of instruction,
	 * when in simulation mode
	 * NOT TESTED!!!!!
	 * 
	 * @param instruction
	 * @return
	 */
	private boolean hasOperands(String instruction) {
		if ("ret".equals(instruction))
			return false;
		else
			return true;
	}

	/**
	 * This method returns the amount of positions allowed in the memory
	 * of this architecture
	 * NOT TESTED!!!!!!!
	 * 
	 * @return
	 */
	public int getMemorySize() {
		return memorySize;
	}

	public static void main(String[] args) throws IOException {
		Architecture arch = new Architecture(true);
		arch.readExec("program");
		arch.controlUnitEexec();
	}

}
