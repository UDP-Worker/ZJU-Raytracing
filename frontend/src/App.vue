<template>
  <div class="container">
    <h1>光学系统设置</h1>
    <table>
      <thead>
        <tr>
          <th>曲率半径 r</th>
          <th>厚度 d</th>
          <th>n1</th>
          <th>n2</th>
          <th></th>
        </tr>
      </thead>
      <tbody>
        <tr v-for="(s, i) in surfaces" :key="i">
          <td><input type="number" v-model.number="s.r" /></td>
          <td><input type="number" v-model.number="s.d" /></td>
          <td><input type="number" v-model.number="s.n1" /></td>
          <td><input type="number" v-model.number="s.n2" /></td>
          <td><button @click="remove(i)">删除</button></td>
        </tr>
      </tbody>
    </table>
    <button @click="add">新增面</button>
    <button @click="trace">开始追迹</button>
    <pre>{{ results }}</pre>
  </div>
</template>

<script setup>
import { ref } from 'vue'

const surfaces = ref([
  { r: 50, d: 5, n1: 1, n2: 1.5 }
])
const results = ref('')

function add() {
  surfaces.value.push({ r: 0, d: 0, n1: 1, n2: 1 })
}
function remove(i) {
  surfaces.value.splice(i, 1)
}
async function trace() {
  results.value = 'loading...'
  try {
    const res = await fetch('/api/trace', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ surfaces: surfaces.value })
    })
    const data = await res.json()
    results.value = JSON.stringify(data, null, 2)
  } catch (e) {
    results.value = 'error'
  }
}
</script>

<style>
body {
  font-family: Arial, sans-serif;
  margin: 20px;
}
.container {
  max-width: 800px;
  margin: auto;
}
table {
  width: 100%;
  border-collapse: collapse;
  margin-bottom: 1em;
}
th, td {
  border: 1px solid #ccc;
  padding: 0.5em;
}
button {
  margin-right: 0.5em;
}
pre {
  background: #f4f4f4;
  padding: 1em;
}
</style>
