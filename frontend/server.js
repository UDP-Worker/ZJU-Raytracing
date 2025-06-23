const express = require('express');
const { execFile } = require('child_process');
const path = require('path');
const fs = require('fs');

const app = express();
const PORT = process.env.PORT || 3000;

// Serve static files from public
app.use(express.static(path.join(__dirname, 'public')));

app.get('/api/results', (req, res) => {
  // Run backend raytracer with sample data
  const backendPath = path.join(__dirname, '../backend/raytracer');
  const systemFile = path.join(__dirname, '../backend/example/system.txt');
  const resultFile = path.join(__dirname, '../backend/example/results.json');

  execFile(backendPath, [systemFile, resultFile], (err) => {
    if (err) {
      console.error(err);
      return res.status(500).json({ error: 'failed to run backend' });
    }
    fs.readFile(resultFile, 'utf8', (err2, data) => {
      if (err2) {
        console.error(err2);
        return res.status(500).json({ error: 'failed to read results' });
      }
      try {
        const json = JSON.parse(data);
        res.json(json);
      } catch (e) {
        res.status(500).json({ error: 'invalid json' });
      }
    });
  });
});

app.listen(PORT, () => {
  console.log(`Server running on http://localhost:${PORT}`);
});
