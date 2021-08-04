//How to get URL content and save into file in Java

/*In this program, we show you how to get content of a page
from URL “www.davidmagar.com.np” and save it into local file drive
named “dvd.dat”. we can save it into file with other extensions like .txt .html etc.
*/


import java.net.*;
import java.io.*;
public class urldemo {
    public static void main(String[] args){
        try {
      // get URL content
      URL url = new URL("http://www.davidmagar.com.np");
      URLConnection conn = url.openConnection();
      // open the stream and put it into BufferedReader
      BufferedReader br = new BufferedReader(
                               new InputStreamReader(conn.getInputStream()));
      String inputLine;
                        // file creating
      BufferedWriter bw = new BufferedWriter(new FileWriter("dvd.dat"));
      while ((inputLine = br.readLine()) != null) {
        bw.write(inputLine);
      }
      bw.close();
      br.close();
      System.out.println("Done");
    } catch (MalformedURLException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }
    }
    }


//if you want to save files in other local drives or paths then

import java.net.*;
import java.io.*;
public class urldemo {
    public static void main(String[] args){
        try {
      // get URL content
      URL url = new URL("http://www.davidmagar.com.np");
      URLConnection conn = url.openConnection();
      // open the stream and put it into BufferedReader
      BufferedReader br = new BufferedReader(
                               new InputStreamReader(conn.getInputStream()));
      String inputLine;
                        
                        //save to this filename
      String fileName = "/home/debid/Documents/dvd.html";
      File file = new File(fileName);
      if (!file.exists()) {
        file.createNewFile();
      }
      //use FileWriter to write file
      FileWriter fw = new FileWriter(file.getAbsoluteFile());
      BufferedWriter bw = new BufferedWriter(fw);
      while ((inputLine = br.readLine()) != null) {
        bw.write(inputLine);
      }
      bw.close();
      br.close();
      System.out.println("Done");
    } catch (MalformedURLException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }
    }
    }