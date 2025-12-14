SELECT * FROM notes
WHERE to_tsvector(note_text) @@ plainto_tsquery('informatics');