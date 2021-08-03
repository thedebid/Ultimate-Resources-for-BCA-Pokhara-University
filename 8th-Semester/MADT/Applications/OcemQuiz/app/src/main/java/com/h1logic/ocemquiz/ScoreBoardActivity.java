package com.h1logic.ocemquiz;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;

import com.h1logic.ocemquiz.MyAdapter;
import com.h1logic.ocemquiz.Score;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;

public class ScoreBoardActivity extends AppCompatActivity {

    RecyclerView rcv;
    MyAdapter adapter;
    private ArrayList<Score> data;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_score_board);

        rcv = findViewById(R.id.rvScoreBoard);

        data = new ArrayList<>();

        new NetworkAsyncTask().execute();
    }

    private class NetworkAsyncTask extends AsyncTask<Void, Void, String> {

        @Override
        protected String doInBackground(Void... voids) {
            String finalResult = "";

            try {
                //1. Declare URL Connection.
                URL url = new URL("https://ocemquiz.herokuapp.com/scoreboard");
                HttpURLConnection connection = (HttpURLConnection) url.openConnection();

                //2. Open InputStream to connection.
                connection.connect();
                InputStream in = connection.getInputStream();

                //3. Download and decode the string response using builder.
                StringBuilder stringBuilder = new StringBuilder();
                BufferedReader reader = new BufferedReader(new InputStreamReader(in));

                String line;

                while ((line = reader.readLine()) != null) {
                    stringBuilder.append(line);
                }

                finalResult = stringBuilder.toString();

            } catch (MalformedURLException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }

            return finalResult;
        }

        @Override
        protected void onPostExecute(String s) {
            super.onPostExecute(s);
            Log.v("SCOREBOARD", "Final Result " + s);


            try {
                JSONArray jsonArray = new JSONArray(s);

                for (int i = 0; i < jsonArray.length(); i++) {
                    Score article = new Score();
                    JSONObject score = jsonArray.getJSONObject(i);
                    JSONObject person = score.getJSONObject("person");
                    int uid = person.getInt("uid");
                    String name = person.getString("name");
                    int points = score.getInt("points");
                    Log.v("OUTPUT", uid + "  " + name + " " + points);
                    article.setUid(i+1);
                    article.setName(name);
                    article.setPoints(points + "");
                    data.add(article);
                }
            } catch (JSONException e) {
                e.printStackTrace();
            }

            adapter = new MyAdapter(data);
            rcv.setAdapter(adapter);
            rcv.setLayoutManager(new LinearLayoutManager(getApplicationContext()));
            adapter.notifyDataSetChanged();
        }
    }
}
