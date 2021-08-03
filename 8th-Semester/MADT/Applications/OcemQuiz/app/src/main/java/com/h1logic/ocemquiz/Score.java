package com.h1logic.ocemquiz;

public class Score {

    private int uid;
    private String name;
    private String points;

    public Score(int mUid, String mName, String mPoints){
        uid = mUid;
        name = mName;
        points = mPoints;
    }
    public Score(){

    }

    public int getUid() {
        return uid;
    }

    public void setUid(int uid) {
        this.uid = uid;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPoints() {
        return points;
    }

    public void setPoints(String points) {
        this.points = points;
    }
}