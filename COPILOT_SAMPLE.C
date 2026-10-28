#include <stdio.h>

int main(void) {
	puts("<!doctype html>");
	puts("<html lang='en'>");
	puts("<head>");
	puts("  <meta charset='utf-8'>");
	puts("  <meta name='viewport' content='width=device-width, initial-scale=1'>");
	puts("  <title>Calculator</title>");
	puts("  <style>");
	puts("    *{box-sizing:border-box}body{margin:0;min-height:100vh;display:grid;place-items:center;background:linear-gradient(135deg,#dbeafe,#f5f3ff);font-family:system-ui,-apple-system,Segoe UI,sans-serif;color:#172033}.calculator{width:min(360px,92vw);padding:22px;border-radius:26px;background:#172033;box-shadow:0 24px 60px #25304c55}.heading{display:flex;justify-content:space-between;align-items:center;color:#cbd5e1;margin:0 3px 18px;font-size:14px;letter-spacing:.08em;text-transform:uppercase}.screen{height:112px;padding:12px 8px;display:flex;flex-direction:column;justify-content:flex-end;align-items:flex-end;overflow:hidden;color:white}.previous{height:25px;color:#94a3b8;font-size:16px}.current{max-width:100%;overflow:hidden;text-overflow:ellipsis;font-size:46px;font-weight:300;white-space:nowrap}.keys{display:grid;grid-template-columns:repeat(4,1fr);gap:10px}.keys button{height:62px;border:0;border-radius:17px;background:#26344d;color:#f8fafc;font-size:21px;cursor:pointer;transition:transform .12s,filter .12s}.keys button:hover{filter:brightness(1.2)}.keys button:active{transform:scale(.94)}.keys .utility{background:#dbe4f0;color:#172033}.keys .operator{background:#4263eb;color:white}.keys .equals{background:#22c55e;color:#052e16}.keys .zero{grid-column:span 2}.hint{text-align:center;color:#94a3b8;font-size:12px;margin:17px 0 0}");
	puts("  </style>");
	puts("</head>");
	puts("<body>");
	puts("  <main class='calculator' aria-label='Calculator'>");
	puts("    <div class='heading'><span>Calculator</span><span>⌘</span></div>");
	puts("    <section class='screen' aria-live='polite'><div class='previous' id='previous'></div><div class='current' id='display'>0</div></section>");
	puts("    <section class='keys'>");
	puts("      <button class='utility' data-action='clear'>AC</button><button class='utility' data-action='sign'>±</button><button class='utility' data-action='percent'>%</button><button class='operator' data-op='÷'>÷</button>");
	puts("      <button data-digit='7'>7</button><button data-digit='8'>8</button><button data-digit='9'>9</button><button class='operator' data-op='×'>×</button>");
	puts("      <button data-digit='4'>4</button><button data-digit='5'>5</button><button data-digit='6'>6</button><button class='operator' data-op='−'>−</button>");
	puts("      <button data-digit='1'>1</button><button data-digit='2'>2</button><button data-digit='3'>3</button><button class='operator' data-op='+'>+</button>");
	puts("      <button class='zero' data-digit='0'>0</button><button data-action='decimal'>.</button><button class='equals' data-action='equals'>=</button>");
	puts("    </section><p class='hint'>Use your keyboard or click the buttons</p>");
	puts("  </main>");
	puts("  <script>");
	puts("    const display=document.getElementById('display'),previous=document.getElementById('previous');let value='0',saved=null,operation=null,replace=true;");
	puts("    function render(){display.textContent=value;previous.textContent=saved===null?'':saved+' '+(operation||'')}");
	puts("    function inputDigit(d){if(replace){value=d;replace=false}else if(value.length<14)value=value==='0'?d:value+d;render()}");
	puts("    function choose(op){if(operation&&!replace)calculate();saved=Number(value);operation=op;replace=true;render()}");
	puts("    function calculate(){if(operation===null||saved===null)return;const a=saved,b=Number(value);let result=operation==='+'?a+b:operation==='−'?a-b:operation==='×'?a*b:b===0?NaN:a/b;value=Number.isFinite(result)?String(Number(result.toPrecision(10))):'Error';saved=null;operation=null;replace=true;render()}");
	puts("    document.querySelector('.keys').addEventListener('click',e=>{const b=e.target.closest('button');if(!b)return;if(b.dataset.digit!==undefined)inputDigit(b.dataset.digit);else if(b.dataset.op)choose(b.dataset.op);else switch(b.dataset.action){case'clear':value='0';saved=null;operation=null;replace=true;render();break;case'decimal':if(replace){value='0.';replace=false}else if(!value.includes('.'))value+='.';render();break;case'sign':if(value!=='0'&&value!=='Error')value=value.startsWith('-')?value.slice(1):'-'+value;render();break;case'percent':value=String(Number(value)/100);replace=true;render();break;case'equals':calculate();}});");
	puts("    document.addEventListener('keydown',e=>{if(/^\\d$/.test(e.key))inputDigit(e.key);else if(e.key==='.')document.querySelector('[data-action=decimal]').click();else if(e.key==='Enter'||e.key==='=')calculate();else if(e.key==='Escape'){document.querySelector('[data-action=clear]').click()}else if(e.key==='Backspace'){value=value.length>1?value.slice(0,-1):'0';render()}else if(e.key==='+')choose('+');else if(e.key==='-')choose('−');else if(e.key==='*')choose('×');else if(e.key==='/'){e.preventDefault();choose('÷')}});");
	puts("  </script>");
	puts("</body></html>");
	return 0;
}
