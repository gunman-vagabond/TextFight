package com.gunman.shootinggame2;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

import android.os.Handler;
import android.os.Message;
import java.util.Timer;
import java.util.TimerTask;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("mylib");
    }

    public native String getStringFromJNI(int i);
    public native String getScreenFromJNI();
    public native String NTmainJNI();

    String screen;

    String insertNewline(StringBuilder str){
        StringBuilder ret = new StringBuilder("");
        for(int i=0;i<25;i++){
            ret.append(str.substring(i*80,(i+1)*80)).append('\n');
        }
        return ret.toString();
    }

    TextView message;
    Handler handler;
    Timer   mTimer   = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

//        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
//        setSupportActionBar(toolbar);

        message = (TextView)this.findViewById(R.id.screen);


        //Timerのスレッドでは、textView を直接触れないので、handler経由でメッセージング
        handler = new Handler(){
            public void handleMessage(Message msg){
                screen = getScreenFromJNI();
                message.setText(insertNewline(new StringBuilder(screen)));
            }
        };

        TimerTask timerTask = new TimerTask() {
            @Override
            public void run(){
                //textView を直接触れない、handler 経由でメッセージング
                handler.sendMessage(new Message());
            }
        };

        //定期タイマ：300マイクロ秒ごとに timerTask を呼び出す
        mTimer = new Timer(true);
        mTimer.scheduleAtFixedRate(timerTask, 0, 300);

//        screen = getScreenFromJNI();
//        message.setText(insertNewline(new StringBuilder(screen)));
//        message.setText("getStringFromJNI(0)");

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
//                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
//                        .setAction("Action", null).show();
                Snackbar.make(view, screen, Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });
//        NTmainJNI();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
