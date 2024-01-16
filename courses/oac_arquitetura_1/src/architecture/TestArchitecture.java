package architecture;

import static org.junit.Assert.*;

import java.io.IOException;
import java.util.ArrayList;

import org.junit.Test;

import components.Memory;

public class TestArchitecture {

	// uncomment the anotation below to run the architecture showing components
	// status
	// @Test
	public void testShowComponentes() {

		// a complete test (for visual purposes only).
		// a single code as follows
		// ldi 2
		// store 40
		// ldi -4
		// point:
		// store 41 //mem[41]=-4 (then -3, -2, -1, 0)
		// read 40
		// add 40 //mem[40] + mem[40]
		// store 40 //result must be in 40
		// read 41
		// inc
		// jn point
		// end

		Architecture arch = new Architecture(true);
		arch.getMemory().getDataList()[0] = 7;
		arch.getMemory().getDataList()[1] = 2;
		arch.getMemory().getDataList()[2] = 6;
		arch.getMemory().getDataList()[3] = 40;
		arch.getMemory().getDataList()[4] = 7;
		arch.getMemory().getDataList()[5] = -4;
		arch.getMemory().getDataList()[6] = 6;
		arch.getMemory().getDataList()[7] = 41;
		arch.getMemory().getDataList()[8] = 5;
		arch.getMemory().getDataList()[9] = 40;
		arch.getMemory().getDataList()[10] = 0;
		arch.getMemory().getDataList()[11] = 40;
		arch.getMemory().getDataList()[12] = 6;
		arch.getMemory().getDataList()[13] = 40;
		arch.getMemory().getDataList()[14] = 5;
		arch.getMemory().getDataList()[15] = 41;
		arch.getMemory().getDataList()[16] = 8;
		arch.getMemory().getDataList()[17] = 4;
		arch.getMemory().getDataList()[18] = 6;
		arch.getMemory().getDataList()[19] = -1;
		arch.getMemory().getDataList()[40] = 0;
		arch.getMemory().getDataList()[41] = 0;
		// now the program and the variables are stored. we can run
		arch.controlUnitEexec();

	}

	@Test
	public void testAddRegReg() 
	{	
		Architecture arch = new Architecture();

		// Storing the number 1 in the memory, in position 31
		arch.getExtbus1().put(31);
		arch.getMemory().store();
		arch.getExtbus1().put(1);
		arch.getMemory().store();

		// Storing the number 0 in the memory, in position 32
		arch.getExtbus1().put(32);
		arch.getMemory().store();
		arch.getExtbus1().put(0);
		arch.getMemory().store();

		// Making PC points to position 30
		arch.getExtbus1().put(30);
		arch.getPC().store();

		// Now setting the registers values
		arch.getExtbus1().put(5);
		arch.getRegistersList().get(1).store(); // RPG1 has 5
		arch.getExtbus1().put(45);
		arch.getRegistersList().get(0).store(); // RPG0 has 45

		// Executing the command add REG1 REG0.
		arch.addRegReg();

		// Testing if REG0 stored the result of the sum
		arch.getRegistersList().get(1).read();
		assertEquals(5, arch.getExtbus1().get());
		arch.getRegistersList().get(0).read();
		assertEquals(50, arch.getExtbus1().get());

		// Testing if PC points to 3 positions after the original
		// PC was pointing to 30; now it must be pointing to 33
		arch.getPC().read();
		assertEquals(33, arch.getExtbus1().get());
	}

	@Test
	public void testCallMem() 
	{	
		Architecture arch = new Architecture();

		// Storing the number 5 in the memory, in position 2
		arch.getExtbus1().put(2);
		arch.getMemory().store();
		arch.getExtbus1().put(5);
		arch.getMemory().store();

		// Storing the number 3 in the memory, in position 100
		arch.getExtbus1().put(3);
		arch.getMemory().store();
		arch.getExtbus1().put(100);
		arch.getMemory().store();
		
		
		arch.getIntbus2().put(1);
		arch.getPC().internalStore();

		// Storing the number 40 in the stack top
		arch.getIntbus2().put(40);
		arch.getStackTop().internalStore();

		arch.callMem();

		arch.getStackTop().internalRead();
		assertEquals(41, arch.getIntbus2().get());

		arch.getPC().read();
		assertEquals(5, arch.getExtbus1().get());
	}

	@Test
	public void testRet() 
	{	
		Architecture arch = new Architecture();
		
		// Storing the number 3 in the memory, in position 40
		arch.getExtbus1().put(40);
		arch.getMemory().store();
		arch.getExtbus1().put(3);
		arch.getMemory().store();

		arch.getIntbus2().put(20);
		arch.getPC().internalStore();

		// Storing the number 41 in the stack top
		arch.getIntbus2().put(41);
		arch.getStackTop().internalStore();

		// Executing the command ret.
		arch.ret();

		// Testing if PC stored the result of the pop() = stackTop--
		arch.getPC().read();
		assertEquals(3, arch.getExtbus1().get());

		arch.getStackTop().internalRead();
		assertEquals(40, arch.getIntbus2().get());
	}

	@Test
	public void testFillCommandsList() {
		Architecture arch = new Architecture();
		ArrayList<String> commands = arch.getCommandsList();
		assertTrue("addRegReg".equals(commands.get(0)));
		assertTrue("addMemReg".equals(commands.get(1)));
		assertTrue("addRegMem".equals(commands.get(2)));
		assertTrue("subRegReg".equals(commands.get(3)));
		assertTrue("subMemReg".equals(commands.get(4)));
		assertTrue("subRegMem".equals(commands.get(5)));
		assertTrue("moveRegReg".equals(commands.get(6)));
		assertTrue("moveMemReg".equals(commands.get(7)));
		assertTrue("moveRegMem".equals(commands.get(8)));
		assertTrue("moveImmReg".equals(commands.get(9)));
		assertTrue("incReg".equals(commands.get(10)));
		assertTrue("incMem".equals(commands.get(11)));
		assertTrue("jmpMem".equals(commands.get(12)));
		assertTrue("jnMem".equals(commands.get(13)));
		assertTrue("jzMem".equals(commands.get(14)));
		assertTrue("jnzMem".equals(commands.get(15)));
		assertTrue("jeqRegRegMem".equals(commands.get(16)));
		assertTrue("jgtRegRegMem".equals(commands.get(17)));
		assertTrue("jlwRegRegMem".equals(commands.get(18)));
		assertTrue("callMem".equals(commands.get(19)));
		assertTrue("ret".equals(commands.get(20)));
	}

	@Test
	public void testReadExec() throws IOException {
		Architecture arch = new Architecture();
		arch.readExec("testFile");
		assertEquals(5, arch.getMemory().getDataList()[0]);
		assertEquals(4, arch.getMemory().getDataList()[1]);
		assertEquals(3, arch.getMemory().getDataList()[2]);
		assertEquals(2, arch.getMemory().getDataList()[3]);
		assertEquals(1, arch.getMemory().getDataList()[4]);
		assertEquals(0, arch.getMemory().getDataList()[5]);
	}

	public static void main(String[] args) throws IOException {
		TestArchitecture test_arch = new TestArchitecture();
		test_arch.testCallMem();
		test_arch.testRet();
	}
}



