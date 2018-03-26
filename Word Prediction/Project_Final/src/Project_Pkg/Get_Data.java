package Project_Pkg;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Get_Data {
	public static void main(String [] args){
		String pkg_path = "/Users/Jason/Documents/workspace/Project_Final/";//the package for the files
		String doc_path = pkg_path+"src/Project_Pkg/DocumentWords.txt";//Document.txt
//		String vocab_path = pkg_path+"src/Project_Pkg/Vocabulary.txt";//Vocabulary.txt
		try{
			Map<String, ArrayList<String>> doc = read_document(doc_path);
//			ArrayList<String> arr = read_vocab(vocab_path);
			Map<String, ArrayList<String>> reversed_map=build_reversedmap(doc);
			Map<String, ArrayList<String>> filtered_map=filetered_doc(reversed_map,1);
			ArrayList<String> word_list = get_filtered_word_list(filtered_map);
			gen_filtered_doc(doc_path,word_list);
		} catch(Exception e){
			e.printStackTrace();
			System.out.println("ERROR in Data Manipulation");
		}	
	}
	
	//generate the new file with all words have frequency above threshold and one file with header id for clustering
	/**Fiel Generated: filtered-1.txt, cluster_doc.txt**/
	public static void gen_filtered_doc(String doc_path, ArrayList<String> list){
		try {
			String sCurrentLine;
			File f = new File("filtered-1.txt");
			BufferedWriter out=new BufferedWriter(new FileWriter(f, true));
			File f2 = new File("cluster_doc.txt");
			BufferedWriter out2=new BufferedWriter(new FileWriter(f2, true));
			BufferedReader br=new BufferedReader(new FileReader(doc_path));	
			while ((sCurrentLine = br.readLine()) != null) {
				ArrayList<String> a = new ArrayList<String>();
				String temp = sCurrentLine;
				String [] itr=temp.split(",");
				String id=itr[0];
				out2.write(id+",");
				for(int i=2;i<itr.length;i++){
					if(list.contains(itr[i])){
						a.add(itr[i]);
					}
				}
				for(int i=0;i<a.size();i++){
					if(i!=a.size()-1){
						out.write(a.get(i)+",");
						out2.write(a.get(i)+",");
					} else{
						out.write(a.get(i)+"\n");
						out2.write(a.get(i)+"\n");
					}
				}
			}	
			System.out.println("Filter Document Done");	
			br.close();
			out.close();
			out2.close();
		}catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	//return a list of words with frequency above threshold
	public static ArrayList<String> get_filtered_word_list(Map<String, ArrayList<String>> map){
		ArrayList<String> result = new ArrayList<String>();	
		for (Map.Entry<String, ArrayList<String>> entry:map.entrySet()) {
		    String key = entry.getKey();
		    result.add(key);
		}
		return result;
	}
	
	//return the map with key:words that are shared by at least n essays
	public static Map<String, ArrayList<String>> filetered_doc(Map<String, ArrayList<String>> map, int threshold){
		Map<String, ArrayList<String>> filter = new HashMap<String, ArrayList<String>>();
		for (Map.Entry<String, ArrayList<String>> entry:map.entrySet()) {
		    String key = entry.getKey();
		    ArrayList<String> value = entry.getValue();
		    if(value.size()>threshold){
		    	filter.put(key, value);
		    }
		}
		return filter;
	}
	
	//build the reversed map, key:words,value:the essay ids sharing the key
	public static Map<String, ArrayList<String>> build_reversedmap(Map<String, ArrayList<String>> document){
		Map<String, ArrayList<String>> map =  new HashMap<String, ArrayList<String>>();
		for (Map.Entry<String, ArrayList<String>> entry:document.entrySet()) {
		    String key = entry.getKey();
		    ArrayList<String> temp = entry.getValue();		    
		    for(int i = 0; i < temp.size(); i++){
		    	ArrayList<String> a = new ArrayList<String>();
		    	if(map.containsKey(temp.get(i))){
		    		a = map.get(temp.get(i));
		    		a.add(key);
		    		map.put(temp.get(i), a);
		    	} else{
		    		a.add(key);
		    		map.put(temp.get(i), a);
		    	}
		    }
		}
		return map;
	}
	
	//Read the DocuemntWords.txt into an arraylist
	public static Map<String, ArrayList<String>> read_document(String file_path){
		Map<String, ArrayList<String>> map = new HashMap<String, ArrayList<String>>();		
		BufferedReader br = null;
		try {
			String sCurrentLine;
			br = new BufferedReader(new FileReader(file_path));
			while ((sCurrentLine = br.readLine()) != null) {
				ArrayList<String> wds = new ArrayList<String>();
				String temp = sCurrentLine;
				String [] itr = temp.split(",");
				String id = itr[0];		
				for(int i = 2; i < itr.length-2; i++){
					wds.add(itr[i]);
				}
				Collections.sort(wds);
//				System.out.print(id+"("+wds.size()+"):");
//				for(int i = 0; i < wds.size(); i++){
//					System.out.print(wds.get(i)+",");
//				}
//				System.out.println();
				if(map.containsKey(id)){
					System.out.println("Key duplicated:"+id);
				} else{
					map.put(id, wds);
				}
			}
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
		} 
		return map;
	}
	
	//Read the Vocabulary.txt into an arraylist
	public static ArrayList<String> read_vocab(String file_path){
		ArrayList<String> arr = new ArrayList<String>();
		BufferedReader br = null;
		try {
			String sCurrentLine;
			br = new BufferedReader(new FileReader(file_path));
			while ((sCurrentLine = br.readLine()) != null) {
				arr.add(sCurrentLine);	
			}
//			System.out.println(arr.size());
			br.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		return arr;
	}
}
