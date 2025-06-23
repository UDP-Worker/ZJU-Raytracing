const express = require('express');
const { execFile } = require('child_process');
const path = require('path');
const fs = require('fs');
const os = require('os');

const app = express();
const PORT = process.env.PORT || 3000;

// Parse JSON bodies from frontend
app.use(express.json());
// Serve built static files
app.use(express.static(path.join(__dirname, 'dist')));

app.post('/api/trace', (req, res) => {
  const surfaces = req.body.surfaces;
  if (!Array.isArray(surfaces)) {
    return res.status(400).json({ error: 'invalid input' });
  }

  const backendPath = path.join(__dirname, '../backend/raytracer');
  const systemFile = path.join(os.tmpdir(), 'system.txt');
  const resultFile = path.join(os.tmpdir(), 'results.json');

  const lines = [String(surfaces.length)];
  for (const s of surfaces) {
    const r = s.r ?? 0;
    const n1 = s.n1 ?? 1;
    const n2 = s.n2 ?? 1;
    const d = s.d ?? 0;
    lines.push(`${r} ${n1} ${n2} ${d}`);
  }
  fs.writeFileSync(systemFile, lines.join('\n'));

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
