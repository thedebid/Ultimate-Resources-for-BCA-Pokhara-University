package com.h1logic.ocemquiz;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

import android.graphics.Color;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

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
import java.text.SimpleDateFormat;
import java.util.Date;

public class QuizActivity extends AppCompatActivity {

    TextView tvQuestion;
    TextView tvOption1;
    TextView tvOption2;
    TextView tvOption3;
    TextView tvOption4;
    TextView tvQuestionNo;
    Button btCheck;
    TextView selectedView = null;
    String question_id;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_quiz);
        tvQuestion = findViewById(R.id.tvQuestion);
        tvOption1 = findViewById(R.id.tvOption1);
        tvOption2 = findViewById(R.id.tvOption2);
        tvOption3 = findViewById(R.id.tvOption3);
        tvOption4 = findViewById(R.id.tvOption4);
        tvQuestionNo = findViewById(R.id.tvTitle);
        btCheck = findViewById(R.id.btCheck);


        new NetworkAsyncTask().execute();

        btCheck.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendAnswerToServerForVerificaition();
            }
        });

        tvOption1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                changeBGToSelected((TextView) v);
            }
        });

        tvOption2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                changeBGToSelected((TextView) v);
            }
        });

        tvOption3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                changeBGToSelected((TextView) v);
            }
        });
        tvOption4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                changeBGToSelected((TextView) v);
            }
        });

    }

    private void changeBGToSelected(TextView v) {
        if (selectedView != null) {
            selectedView.setTextColor(Color.parseColor("#99000000"));
            selectedView.setBackground(ContextCompat.getDrawable(getApplicationContext(), R.drawable.option_background));
        }
        //set selectedView to be current selected view
        selectedView = v;
        //change selected view to be green
        selectedView.setTextColor(Color.parseColor("#ffffff"));
        selectedView.setBackgroundColor(Color.parseColor("#00c853"));
    }


    private void sendAnswerToServerForVerificaition() {
      //  Toast.makeText(this, "Answer is " + selectedView.getText().toString(), Toast.LENGTH_SHORT).show();
        String answer = selectedView.getText().toString();
        new CheckAnswerAsyncTask().execute(question_id,answer);
    }

    private class NetworkAsyncTask extends AsyncTask<Void, Void, String> {

        @Override
        protected String doInBackground(Void... voids) {
            String finalResult = "";

            try {
                //1. Declare URL Connection.
                URL url = new URL("https://ocemquiz.herokuapp.com/question");
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
            Log.v("TAGESTO", "Final Result " + s);

            try {
                JSONArray jsonArray = new JSONArray(s);
                JSONObject firstQuestion = jsonArray.getJSONObject(0);
                String title = firstQuestion.getString("title");
                String questionNo = firstQuestion.getString("qid");
                question_id = questionNo;
                JSONObject options = firstQuestion.getJSONObject("answers");
                String firstOption = options.getString("a1");
                String secondOption = options.getString("a2");
                String thirdOption = options.getString("a3");
                String fourthOption = options.getString("a4");

                tvQuestion.setText(title);
                tvOption1.setText(firstOption);
                tvOption2.setText(secondOption);
                tvOption3.setText(thirdOption);
                tvOption4.setText(fourthOption);
                tvQuestionNo.setText(questionNo + "");

                final TextView tvTimer = (TextView) findViewById(R.id.tvTimer);
                new CountDownTimer(30 * 1000, 1000) {

                    public void onTick(long millisUntilFinished) {
                        tvTimer.setText("00:" + new SimpleDateFormat("ss").format(new Date(millisUntilFinished)));
                    }

                    public void onFinish() {
                        tvTimer.setText("expired");

                    }
                }.start();


            } catch (JSONException e) {
                e.printStackTrace();
            }

        }
    }


    private class CheckAnswerAsyncTask extends AsyncTask<String, Void, String> {

        @Override
        protected String doInBackground(String... strings) {
            String finalResult = "";
             String qid = strings[0];
             String answer = strings[1];

            Log.v("TAGESTO", "FQid " + qid);
            Log.v("TAGESTO", "Answer" + answer);

            try {
                //1. Declare URL Connection.
                URL url = new URL("https://ocemquiz.herokuapp.com/question/checkAnswer/"+ qid +"/"+ answer +"");
                Log.v("Sdc",url.toString());
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
            Log.v("TAGESTO", " Result " + s);
            try {
                //conver String to Json
                JSONObject resultInJsob = new JSONObject(s);
                //extract msg from jsob object
                String msg = resultInJsob.getString("msg");
                //Make Toast
                makeToast(msg);
            }   catch (JSONException e) {
            e.printStackTrace();
        }
        }
    }
    public void makeToast(String msg){

        Toast.makeText(this, msg, Toast.LENGTH_SHORT).show();
    }
}