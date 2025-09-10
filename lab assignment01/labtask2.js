function SolveThis(obj) {
  let res = {};

  for (let k in obj) {
    let v = obj[k];
    if (k==="sum") res[k]=v.reduce((a,b)=>a+b,0);
    else if (k==="max") res[k]=Math.max(...v);
    else if (k==="min") res[k]=Math.min(...v);
    else if (k==="abs") res[k]=Math.abs(v[0]);
    else if (k==="ceil") res[k]=Math.ceil(v[0]);
    else if (k==="floor") res[k]=Math.floor(v[0]);
    else if (k==="round") res[k]=Math.round(v[0]);
    else if (k==="random") res[k]=Math.random();
  }

  return res;
}

console.log(SolveThis({ sum:[3,2,4], max:[2,4,3,5], min:[5,3,4,3] }));
