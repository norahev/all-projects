package edu.harvard.cs50.notes;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.ItemTouchHelper;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import androidx.room.Room;

import android.os.Bundle;
import android.view.View;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

public class MainActivity extends AppCompatActivity {
    private RecyclerView recyclerView;
    private NotesAdapter adapter;
    private RecyclerView.LayoutManager layoutManager;
    public static NotesDatabase database;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        database = Room.databaseBuilder(getApplicationContext(), NotesDatabase.class, "notes")
                .allowMainThreadQueries().build();
        recyclerView = findViewById(R.id.recycler_view);
        new ItemTouchHelper(touchHelper).attachToRecyclerView(recyclerView);
        layoutManager = new LinearLayoutManager(this);
        adapter = new NotesAdapter();
        recyclerView.setLayoutManager(layoutManager);
        recyclerView.setAdapter(adapter);
        FloatingActionButton button = findViewById(R.id.add_note_button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                database.noteDao().create();
                adapter.reload();
            }
        });
    }

    @Override
    protected void onResume() {
        super.onResume();
        adapter.reload();
    }
    ItemTouchHelper.SimpleCallback touchHelper = new ItemTouchHelper.SimpleCallback(0, ItemTouchHelper.LEFT) {
        @Override
        public boolean onMove(@NonNull RecyclerView recyclerView, @NonNull RecyclerView.ViewHolder viewHolder, @NonNull RecyclerView.ViewHolder target) {
            return false;
        }

        @Override
        public void onSwiped(@NonNull RecyclerView.ViewHolder viewHolder, int direction) {
            adapter.remove(viewHolder.getAdapterPosition());
            adapter.notifyDataSetChanged();
        }
    };
}
