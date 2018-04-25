package lab07;

import java.awt.List;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

public class FileBuffer {
	private String filename;

	public FileBuffer(String filename) {
		this.filename = filename;
		
		Path filePath = Paths.get(filename);
		
		try{
			java.util.List<String> lines = Files.readAllLines(filePath);
		}
		catch(IOException e){
			ArrayList<String> lines = new ArrayList<>();
		}
	}
	
	@Override

	
	
}
