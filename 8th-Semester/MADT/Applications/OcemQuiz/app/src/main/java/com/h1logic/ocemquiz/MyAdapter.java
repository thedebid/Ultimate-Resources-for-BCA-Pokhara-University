package com.h1logic.ocemquiz;


import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class MyAdapter extends RecyclerView.Adapter<MyAdapter.MyViewHolder> {

    List<Score> data;

    public MyAdapter(List<Score> data) {

        this.data = data;
    }


    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {

        LayoutInflater inflater = LayoutInflater.from(parent.getContext());
        View view = inflater.inflate(R.layout.item_score_board,parent,false);
        return  new MyViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder holder, int position) {

        Score score = data.get(position);
        holder.id.setText(score.getUid() +"");
        holder.name.setText(score.getName());
        holder.points.setText(score.getPoints());
    }

    @Override
    public int getItemCount() {
        return  data.size();
    }



    public class MyViewHolder extends RecyclerView.ViewHolder {

        TextView id;
        TextView name;
        TextView points;

        public MyViewHolder(@NonNull View itemView) {
            super(itemView);
            id = itemView.findViewById(R.id.tvuid);
            name = itemView.findViewById(R.id.tvName);
            points = itemView.findViewById(R.id.tvScore);
        }
    }

}

