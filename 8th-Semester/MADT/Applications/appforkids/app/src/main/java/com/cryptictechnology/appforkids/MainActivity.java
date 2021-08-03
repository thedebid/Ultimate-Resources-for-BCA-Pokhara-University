package com.cryptictechnology.appforkids;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.google.android.material.snackbar.Snackbar;

import java.util.Random;

public class MainActivity extends AppCompatActivity {

    Button btFirst;
    Button btSecond;
    Random rand = new Random();


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btFirst = findViewById(R.id.btFirst);
        btSecond = findViewById(R.id.btSecond);

        //generate random values from 0-100
        int first_random = rand.nextInt(100);
        int second_random = rand.nextInt(100);

        //setting text onrand button
        btFirst.setText(Integer.toString(first_random));
        btSecond.setText(Integer.toString(second_random));

        //Click Listener for Button 1
        btFirst.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (first_random == second_random) {
                    checkAnswer(v, "Equal");
                }
                else if(first_random > second_random){
                    checkAnswer(v, "Right");
                }else{
                    checkAnswer(v,"Wrong");
                }
            }
        });

        //Click Listener for Button 2
        btSecond.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (first_random == second_random) {
                    checkAnswer(v, "Equal");
                }else if (first_random < second_random) {
                    checkAnswer(v,"Right");
                }else{
                    checkAnswer(v,"Wrong");
                }

            }
        });
    }

    //function for checking answer and showing snackbar
    private void checkAnswer(View v,String r) {
        //snackbar
        Snackbar snackbar = Snackbar.make(v, r, Snackbar.LENGTH_LONG);
        snackbar.show();
    }
}