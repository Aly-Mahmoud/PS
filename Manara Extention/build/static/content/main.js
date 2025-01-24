/******/ (function(modules) { // webpackBootstrap
/******/ 	// install a JSONP callback for chunk loading
/******/ 	function webpackJsonpCallback(data) {
/******/ 		var chunkIds = data[0];
/******/ 		var moreModules = data[1];
/******/ 		var executeModules = data[2];
/******/
/******/ 		// add "moreModules" to the modules object,
/******/ 		// then flag all "chunkIds" as loaded and fire callback
/******/ 		var moduleId, chunkId, i = 0, resolves = [];
/******/ 		for(;i < chunkIds.length; i++) {
/******/ 			chunkId = chunkIds[i];
/******/ 			if(Object.prototype.hasOwnProperty.call(installedChunks, chunkId) && installedChunks[chunkId]) {
/******/ 				resolves.push(installedChunks[chunkId][0]);
/******/ 			}
/******/ 			installedChunks[chunkId] = 0;
/******/ 		}
/******/ 		for(moduleId in moreModules) {
/******/ 			if(Object.prototype.hasOwnProperty.call(moreModules, moduleId)) {
/******/ 				modules[moduleId] = moreModules[moduleId];
/******/ 			}
/******/ 		}
/******/ 		if(parentJsonpFunction) parentJsonpFunction(data);
/******/
/******/ 		while(resolves.length) {
/******/ 			resolves.shift()();
/******/ 		}
/******/
/******/ 		// add entry modules from loaded chunk to deferred list
/******/ 		deferredModules.push.apply(deferredModules, executeModules || []);
/******/
/******/ 		// run deferred modules when all chunks ready
/******/ 		return checkDeferredModules();
/******/ 	};
/******/ 	function checkDeferredModules() {
/******/ 		var result;
/******/ 		for(var i = 0; i < deferredModules.length; i++) {
/******/ 			var deferredModule = deferredModules[i];
/******/ 			var fulfilled = true;
/******/ 			for(var j = 1; j < deferredModule.length; j++) {
/******/ 				var depId = deferredModule[j];
/******/ 				if(installedChunks[depId] !== 0) fulfilled = false;
/******/ 			}
/******/ 			if(fulfilled) {
/******/ 				deferredModules.splice(i--, 1);
/******/ 				result = __webpack_require__(__webpack_require__.s = deferredModule[0]);
/******/ 			}
/******/ 		}
/******/
/******/ 		return result;
/******/ 	}
/******/
/******/ 	// The module cache
/******/ 	var installedModules = {};
/******/
/******/ 	// object to store loaded and loading chunks
/******/ 	// undefined = chunk not loaded, null = chunk preloaded/prefetched
/******/ 	// Promise = chunk loading, 0 = chunk loaded
/******/ 	var installedChunks = {
/******/ 		1: 0
/******/ 	};
/******/
/******/ 	var deferredModules = [];
/******/
/******/ 	// script path function
/******/ 	function jsonpScriptSrc(chunkId) {
/******/ 		return __webpack_require__.p + "static/js/" + ({}[chunkId]||chunkId) + "." + {"3":"b6f009c7"}[chunkId] + ".chunk.js"
/******/ 	}
/******/
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/
/******/ 		// Check if module is in cache
/******/ 		if(installedModules[moduleId]) {
/******/ 			return installedModules[moduleId].exports;
/******/ 		}
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = installedModules[moduleId] = {
/******/ 			i: moduleId,
/******/ 			l: false,
/******/ 			exports: {}
/******/ 		};
/******/
/******/ 		// Execute the module function
/******/ 		modules[moduleId].call(module.exports, module, module.exports, __webpack_require__);
/******/
/******/ 		// Flag the module as loaded
/******/ 		module.l = true;
/******/
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/
/******/ 	// This file contains only the entry chunk.
/******/ 	// The chunk loading function for additional chunks
/******/ 	__webpack_require__.e = function requireEnsure(chunkId) {
/******/ 		var promises = [];
/******/
/******/
/******/ 		// JSONP chunk loading for javascript
/******/
/******/ 		var installedChunkData = installedChunks[chunkId];
/******/ 		if(installedChunkData !== 0) { // 0 means "already installed".
/******/
/******/ 			// a Promise means "currently loading".
/******/ 			if(installedChunkData) {
/******/ 				promises.push(installedChunkData[2]);
/******/ 			} else {
/******/ 				// setup Promise in chunk cache
/******/ 				var promise = new Promise(function(resolve, reject) {
/******/ 					installedChunkData = installedChunks[chunkId] = [resolve, reject];
/******/ 				});
/******/ 				promises.push(installedChunkData[2] = promise);
/******/
/******/ 				// start chunk loading
/******/ 				var script = document.createElement('script');
/******/ 				var onScriptComplete;
/******/
/******/ 				script.charset = 'utf-8';
/******/ 				script.timeout = 120;
/******/ 				if (__webpack_require__.nc) {
/******/ 					script.setAttribute("nonce", __webpack_require__.nc);
/******/ 				}
/******/ 				script.src = jsonpScriptSrc(chunkId);
/******/
/******/ 				// create error before stack unwound to get useful stacktrace later
/******/ 				var error = new Error();
/******/ 				onScriptComplete = function (event) {
/******/ 					// avoid mem leaks in IE.
/******/ 					script.onerror = script.onload = null;
/******/ 					clearTimeout(timeout);
/******/ 					var chunk = installedChunks[chunkId];
/******/ 					if(chunk !== 0) {
/******/ 						if(chunk) {
/******/ 							var errorType = event && (event.type === 'load' ? 'missing' : event.type);
/******/ 							var realSrc = event && event.target && event.target.src;
/******/ 							error.message = 'Loading chunk ' + chunkId + ' failed.\n(' + errorType + ': ' + realSrc + ')';
/******/ 							error.name = 'ChunkLoadError';
/******/ 							error.type = errorType;
/******/ 							error.request = realSrc;
/******/ 							chunk[1](error);
/******/ 						}
/******/ 						installedChunks[chunkId] = undefined;
/******/ 					}
/******/ 				};
/******/ 				var timeout = setTimeout(function(){
/******/ 					onScriptComplete({ type: 'timeout', target: script });
/******/ 				}, 120000);
/******/ 				script.onerror = script.onload = onScriptComplete;
/******/ 				document.head.appendChild(script);
/******/ 			}
/******/ 		}
/******/ 		return Promise.all(promises);
/******/ 	};
/******/
/******/ 	// expose the modules object (__webpack_modules__)
/******/ 	__webpack_require__.m = modules;
/******/
/******/ 	// expose the module cache
/******/ 	__webpack_require__.c = installedModules;
/******/
/******/ 	// define getter function for harmony exports
/******/ 	__webpack_require__.d = function(exports, name, getter) {
/******/ 		if(!__webpack_require__.o(exports, name)) {
/******/ 			Object.defineProperty(exports, name, { enumerable: true, get: getter });
/******/ 		}
/******/ 	};
/******/
/******/ 	// define __esModule on exports
/******/ 	__webpack_require__.r = function(exports) {
/******/ 		if(typeof Symbol !== 'undefined' && Symbol.toStringTag) {
/******/ 			Object.defineProperty(exports, Symbol.toStringTag, { value: 'Module' });
/******/ 		}
/******/ 		Object.defineProperty(exports, '__esModule', { value: true });
/******/ 	};
/******/
/******/ 	// create a fake namespace object
/******/ 	// mode & 1: value is a module id, require it
/******/ 	// mode & 2: merge all properties of value into the ns
/******/ 	// mode & 4: return value when already ns object
/******/ 	// mode & 8|1: behave like require
/******/ 	__webpack_require__.t = function(value, mode) {
/******/ 		if(mode & 1) value = __webpack_require__(value);
/******/ 		if(mode & 8) return value;
/******/ 		if((mode & 4) && typeof value === 'object' && value && value.__esModule) return value;
/******/ 		var ns = Object.create(null);
/******/ 		__webpack_require__.r(ns);
/******/ 		Object.defineProperty(ns, 'default', { enumerable: true, value: value });
/******/ 		if(mode & 2 && typeof value != 'string') for(var key in value) __webpack_require__.d(ns, key, function(key) { return value[key]; }.bind(null, key));
/******/ 		return ns;
/******/ 	};
/******/
/******/ 	// getDefaultExport function for compatibility with non-harmony modules
/******/ 	__webpack_require__.n = function(module) {
/******/ 		var getter = module && module.__esModule ?
/******/ 			function getDefault() { return module['default']; } :
/******/ 			function getModuleExports() { return module; };
/******/ 		__webpack_require__.d(getter, 'a', getter);
/******/ 		return getter;
/******/ 	};
/******/
/******/ 	// Object.prototype.hasOwnProperty.call
/******/ 	__webpack_require__.o = function(object, property) { return Object.prototype.hasOwnProperty.call(object, property); };
/******/
/******/ 	// __webpack_public_path__
/******/ 	__webpack_require__.p = "/";
/******/
/******/ 	// on error function for async loading
/******/ 	__webpack_require__.oe = function(err) { console.error(err); throw err; };
/******/
/******/ 	var jsonpArray = this["webpackJsonpchrome-react-seo-extension"] = this["webpackJsonpchrome-react-seo-extension"] || [];
/******/ 	var oldJsonpFunction = jsonpArray.push.bind(jsonpArray);
/******/ 	jsonpArray.push = webpackJsonpCallback;
/******/ 	jsonpArray = jsonpArray.slice();
/******/ 	for(var i = 0; i < jsonpArray.length; i++) webpackJsonpCallback(jsonpArray[i]);
/******/ 	var parentJsonpFunction = oldJsonpFunction;
/******/
/******/
/******/ 	// add entry module to deferred list
/******/ 	deferredModules.push([132,2]);
/******/ 	// run deferred modules when ready
/******/ 	return checkDeferredModules();
/******/ })
/************************************************************************/
/******/ ({

/***/ 132:
/***/ (function(module, exports, __webpack_require__) {

module.exports = __webpack_require__(168);


/***/ }),

/***/ 137:
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),

/***/ 166:
/***/ (function(module, exports, __webpack_require__) {

// extracted by mini-css-extract-plugin

/***/ }),

/***/ 168:
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
// ESM COMPAT FLAG
__webpack_require__.r(__webpack_exports__);

// EXTERNAL MODULE: ./node_modules/react/index.js
var react = __webpack_require__(0);
var react_default = /*#__PURE__*/__webpack_require__.n(react);

// EXTERNAL MODULE: ./node_modules/react-dom/index.js
var react_dom = __webpack_require__(32);
var react_dom_default = /*#__PURE__*/__webpack_require__.n(react_dom);

// EXTERNAL MODULE: ./src/index.css
var src = __webpack_require__(137);

// EXTERNAL MODULE: ./node_modules/@babel/runtime/helpers/esm/slicedToArray.js + 1 modules
var slicedToArray = __webpack_require__(11);

// EXTERNAL MODULE: ./node_modules/@babel/runtime/helpers/esm/regeneratorRuntime.js
var regeneratorRuntime = __webpack_require__(16);

// EXTERNAL MODULE: ./node_modules/@babel/runtime/helpers/esm/asyncToGenerator.js
var asyncToGenerator = __webpack_require__(24);

// EXTERNAL MODULE: ./node_modules/@babel/runtime/helpers/esm/objectSpread2.js
var objectSpread2 = __webpack_require__(29);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/Grid/Grid.js + 2 modules
var Grid = __webpack_require__(239);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/Alert/Alert.js + 8 modules
var Alert = __webpack_require__(230);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/CircularProgress/CircularProgress.js + 1 modules
var CircularProgress = __webpack_require__(249);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/FormControl/FormControl.js + 1 modules
var FormControl = __webpack_require__(251);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/Select/Select.js + 22 modules
var Select = __webpack_require__(229);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/MenuItem/MenuItem.js + 4 modules
var MenuItem = __webpack_require__(233);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/TableHead/TableHead.js + 1 modules
var TableHead = __webpack_require__(241);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/TableCell/TableCell.js + 1 modules
var TableCell = __webpack_require__(243);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/TableRow/TableRow.js + 1 modules
var TableRow = __webpack_require__(242);

// EXTERNAL MODULE: ./node_modules/react/jsx-runtime.js
var jsx_runtime = __webpack_require__(1);

// CONCATENATED MODULE: ./src/components/Table/Header.tsx
function Header(){var headCells=[{id:"title",numeric:false,disablePadding:true,label:"Title"},{id:"difficulty",numeric:false,disablePadding:false,label:"Difficulty"},{id:"submissionStatus",numeric:false,disablePadding:false,label:"Status"}];return/*#__PURE__*/Object(jsx_runtime["jsx"])(TableHead["a" /* default */],{children:/*#__PURE__*/Object(jsx_runtime["jsxs"])(TableRow["a" /* default */],{children:[headCells.map(function(headCell){return/*#__PURE__*/Object(jsx_runtime["jsx"])(TableCell["a" /* default */],{align:headCell.id==="title"?"left":"right",children:headCell.label},headCell.id);}),/*#__PURE__*/Object(jsx_runtime["jsx"])(TableCell["a" /* default */],{},"refresh")]})});}
// EXTERNAL MODULE: ./node_modules/@mui/material/esm/Chip/Chip.js + 2 modules
var Chip = __webpack_require__(235);

// CONCATENATED MODULE: ./src/components/Chips/DifficultyChip.tsx
function DifficultyChip(props){var difficulty=props.difficulty;var getColor=function getColor(difficulty){switch(difficulty.toLowerCase()){case"hard":return"error";case"medium":return"warning";case"easy":return"success";default:return"primary";}};return/*#__PURE__*/Object(jsx_runtime["jsx"])(Chip["a" /* default */],{label:difficulty,color:getColor(difficulty)});}
// CONCATENATED MODULE: ./src/components/Chips/index.tsx

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/Table/Table.js + 1 modules
var Table = __webpack_require__(245);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/TableBody/TableBody.js + 1 modules
var TableBody = __webpack_require__(246);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/TableContainer/TableContainer.js + 1 modules
var TableContainer = __webpack_require__(244);

// EXTERNAL MODULE: ./node_modules/@mui/icons-material/Info.js
var Info = __webpack_require__(109);
var Info_default = /*#__PURE__*/__webpack_require__.n(Info);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/Paper/Paper.js + 2 modules
var Paper = __webpack_require__(236);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/Tooltip/Tooltip.js + 58 modules
var Tooltip = __webpack_require__(228);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/Link/Link.js + 2 modules
var Link = __webpack_require__(237);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/Box/Box.js + 1 modules
var Box = __webpack_require__(248);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/Button/Button.js + 2 modules
var Button = __webpack_require__(238);

// CONCATENATED MODULE: ./src/components/Table/Table.tsx
function EnhancedTable(props){var problems=props.problems,activeProblemSlug=props.activeProblemSlug,problemLoadingStates=props.problemLoadingStates,refreshSubmissionInfo=props.refreshSubmissionInfo,currentScheduleWeek=props.currentScheduleWeek,userId=props.userId;var openProblem=function openProblem(problemSlug){chrome.tabs.create({url:"https://leetcode.com/problems/".concat(problemSlug)});};console.log("Table Schedule Week",{currentScheduleWeek:currentScheduleWeek});return/*#__PURE__*/Object(jsx_runtime["jsx"])(TableContainer["a" /* default */],{component:Paper["a" /* default */],children:/*#__PURE__*/Object(jsx_runtime["jsxs"])(Table["a" /* default */],{"aria-labelledby":"tableTitle",sx:{minWidth:650},size:"medium",children:[/*#__PURE__*/Object(jsx_runtime["jsx"])(Header,{}),/*#__PURE__*/Object(jsx_runtime["jsx"])(TableBody["a" /* default */],{children:problems.map(function(problem,index){var _problem$submission$s,_problem$submission;var labelId="enhanced-table-checkbox-".concat(index);return/*#__PURE__*/Object(jsx_runtime["jsxs"])(TableRow["a" /* default */],{hover:true,tabIndex:-1,children:[/*#__PURE__*/Object(jsx_runtime["jsxs"])(TableCell["a" /* default */],{component:"th",id:labelId,scope:"row",children:[/*#__PURE__*/Object(jsx_runtime["jsx"])(Link["a" /* default */],{className:"problem-title",onClick:function onClick(_e){return openProblem(problem.leetcodeSlug);},children:problem.title}),activeProblemSlug&&activeProblemSlug===problem.leetcodeSlug&&/*#__PURE__*/Object(jsx_runtime["jsxs"])(jsx_runtime["Fragment"],{children:[/*#__PURE__*/Object(jsx_runtime["jsx"])("span",{children:"\xA0(Active)\xA0"}),/*#__PURE__*/Object(jsx_runtime["jsx"])(Tooltip["a" /* default */],{title:"We detected that you're currently working on / browsing this problem",children:/*#__PURE__*/Object(jsx_runtime["jsx"])(Info_default.a,{fontSize:"inherit"})})]})]}),/*#__PURE__*/Object(jsx_runtime["jsx"])(TableCell["a" /* default */],{align:"right",children:/*#__PURE__*/Object(jsx_runtime["jsx"])(DifficultyChip,{difficulty:problem.difficulty})}),/*#__PURE__*/Object(jsx_runtime["jsx"])(TableCell["a" /* default */],{align:"right",children:/*#__PURE__*/Object(jsx_runtime["jsx"])(Box["a" /* default */],{display:"inline",children:problemLoadingStates[problem.leetcodeSlug]?/*#__PURE__*/Object(jsx_runtime["jsx"])(CircularProgress["a" /* default */],{size:"1.5rem"}):/*#__PURE__*/Object(jsx_runtime["jsx"])("p",{children:(_problem$submission$s=(_problem$submission=problem.submission)===null||_problem$submission===void 0?void 0:_problem$submission.status)!==null&&_problem$submission$s!==void 0?_problem$submission$s:"Not Submitted"})})}),/*#__PURE__*/Object(jsx_runtime["jsx"])(TableCell["a" /* default */],{align:"right",children:/*#__PURE__*/Object(jsx_runtime["jsx"])(Box["a" /* default */],{display:"inline",children:/*#__PURE__*/Object(jsx_runtime["jsx"])(Button["a" /* default */],{style:{borderRadius:"45%",border:"solid lightgray",color:"text"},variant:"outlined",onClick:function onClick(){refreshSubmissionInfo(currentScheduleWeek,userId,problem.leetcodeSlug);},children:"Check"})})})]},problem.title);})})]})});}
// CONCATENATED MODULE: ./src/components/Table/index.tsx
/* harmony default export */ var components_Table = (EnhancedTable);
// EXTERNAL MODULE: ./node_modules/@mui/material/esm/LinearProgress/LinearProgress.js + 1 modules
var LinearProgress = __webpack_require__(250);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/Typography/Typography.js + 1 modules
var Typography = __webpack_require__(247);

// CONCATENATED MODULE: ./src/components/Loaders/LinearProgress.tsx
function LinearProgressWithLabel(props){return/*#__PURE__*/Object(jsx_runtime["jsxs"])(Box["a" /* default */],{sx:{display:"flex",alignItems:"center",my:"0.5rem"},children:[/*#__PURE__*/Object(jsx_runtime["jsx"])(Typography["a" /* default */],{variant:"subtitle2",color:"text.secondary",children:"Progress\xA0\xA0"}),/*#__PURE__*/Object(jsx_runtime["jsx"])(Box["a" /* default */],{sx:{width:"100%",mr:1},children:/*#__PURE__*/Object(jsx_runtime["jsx"])(LinearProgress["a" /* default */],Object(objectSpread2["a" /* default */])({variant:"determinate"},props))}),/*#__PURE__*/Object(jsx_runtime["jsx"])(Box["a" /* default */],{sx:{minWidth:35},children:/*#__PURE__*/Object(jsx_runtime["jsx"])(Typography["a" /* default */],{variant:"body2",color:"text.secondary",children:"".concat(Math.round(props.value),"%")})})]});}
// CONCATENATED MODULE: ./src/components/Loaders/index.tsx

// CONCATENATED MODULE: ./src/components/CourseSelection.tsx
function CourseSelection(props){var _props$courses$curren;function saveCourse(course){chrome.storage.local.set({course:course});props.setCourse(course);}var buttons=props.courses&&((_props$courses$curren=props.courses.currentScheduleWeek)===null||_props$courses$curren===void 0?void 0:_props$courses$curren.map(function(course){return/*#__PURE__*/Object(jsx_runtime["jsx"])(Button["a" /* default */],{style:{margin:"1rem"},color:"primary",variant:"contained",fullWidth:true,onClick:function onClick(){return saveCourse(course.modules);},children:course.name});}));return/*#__PURE__*/Object(jsx_runtime["jsx"])("div",{style:{margin:"2rem 0rem",border:"solid 0.1rem lightgrey",borderRadius:"10px",padding:"1rem"},children:/*#__PURE__*/Object(jsx_runtime["jsxs"])(Grid["a" /* default */],{container:true,alignItems:"center",style:{padding:"1rem",textAlign:"center",justifyContent:"center"},children:[/*#__PURE__*/Object(jsx_runtime["jsx"])("h1",{children:"Select Course"}),buttons]})});};
// CONCATENATED MODULE: ./src/helpers/leetcode.ts
var LEETCODE_SESSION="LEETCODE_SESSION";var LEETCODE_CSRF="csrftoken";var LEETCODE_URL="https://leetcode.com";var checkLeetcodeAuth=/*#__PURE__*/function(){var _ref=Object(asyncToGenerator["a" /* default */])(/*#__PURE__*/Object(regeneratorRuntime["a" /* default */])().mark(function _callee(){var csrf,session;return Object(regeneratorRuntime["a" /* default */])().wrap(function _callee$(_context){while(1){switch(_context.prev=_context.next){case 0:_context.next=2;return chrome.cookies.get({name:LEETCODE_CSRF,url:LEETCODE_URL});case 2:csrf=_context.sent;_context.next=5;return chrome.cookies.get({name:LEETCODE_SESSION,url:LEETCODE_URL});case 5:session=_context.sent;if(!(!csrf||!session)){_context.next=9;break;}console.log("LEETCODE AUTH RETURNED NULL");return _context.abrupt("return",null);case 9:return _context.abrupt("return",{csrf:csrf.value,session:session.value});case 10:case"end":return _context.stop();}}},_callee);}));return function checkLeetcodeAuth(){return _ref.apply(this,arguments);};}();var parseProblemSlug=function parseProblemSlug(location){// TODO extract constant
if(location&&location.host==="leetcode.com"){var tokens=location.href.split("/");for(var i=0;i<tokens.length;i++){// TODO extract constant
if(tokens[i]==="problems"&&i+1<tokens.length){return tokens[i+1];}}}return null;};var leetcodeLogout=/*#__PURE__*/function(){var _ref2=Object(asyncToGenerator["a" /* default */])(/*#__PURE__*/Object(regeneratorRuntime["a" /* default */])().mark(function _callee2(){return Object(regeneratorRuntime["a" /* default */])().wrap(function _callee2$(_context2){while(1){switch(_context2.prev=_context2.next){case 0:_context2.next=2;return chrome.cookies.remove({name:LEETCODE_CSRF,url:LEETCODE_URL});case 2:_context2.next=4;return chrome.cookies.remove({name:LEETCODE_SESSION,url:LEETCODE_URL});case 4:return _context2.abrupt("return",null);case 5:case"end":return _context2.stop();}}},_callee2);}));return function leetcodeLogout(){return _ref2.apply(this,arguments);};}();
// CONCATENATED MODULE: ./src/constants.ts
var VERSION='20240926.1125';var ProgramType;(function(ProgramType){ProgramType["COHORT"]="cohort";ProgramType["FLEX"]="flex";})(ProgramType||(ProgramType={}));
// CONCATENATED MODULE: ./src/components/ProblemList.tsx
/* eslint-disable react-hooks/exhaustive-deps */var ProblemList_dates=function dates(selectedScheduleWeek){return/*#__PURE__*/Object(jsx_runtime["jsxs"])(Grid["a" /* default */],{container:true,columnSpacing:1,sx:{my:"0.5rem"},children:[/*#__PURE__*/Object(jsx_runtime["jsxs"])(Grid["a" /* default */],{item:true,xs:4,children:[/*#__PURE__*/Object(jsx_runtime["jsx"])("b",{children:"Start Date:"}),/*#__PURE__*/Object(jsx_runtime["jsx"])("br",{}),/*#__PURE__*/Object(jsx_runtime["jsx"])("p",{children:selectedScheduleWeek.startDateTime.toUTCString()})]}),/*#__PURE__*/Object(jsx_runtime["jsxs"])(Grid["a" /* default */],{item:true,xs:4,children:[/*#__PURE__*/Object(jsx_runtime["jsx"])("b",{children:"End Date:"}),/*#__PURE__*/Object(jsx_runtime["jsx"])("br",{}),/*#__PURE__*/Object(jsx_runtime["jsx"])("p",{children:selectedScheduleWeek.endDateTime.toUTCString()})]})]});};function ProblemListPage(props){var _props$program3;var location=props.location,backendClient=props.backendClient,userId=props.userId;var _useState=Object(react["useState"])(false),_useState2=Object(slicedToArray["a" /* default */])(_useState,2),loading=_useState2[0],setLoading=_useState2[1];var _useState3=Object(react["useState"])(null),_useState4=Object(slicedToArray["a" /* default */])(_useState3,2),error=_useState4[0],setError=_useState4[1];var _useState5=Object(react["useState"])(),_useState6=Object(slicedToArray["a" /* default */])(_useState5,2),selectedWeekId=_useState6[0],setSelectedWeekId=_useState6[1];var _useState7=Object(react["useState"])(null),_useState8=Object(slicedToArray["a" /* default */])(_useState7,2),currentSchedule=_useState8[0],setCurrentSchedule=_useState8[1];var _useState9=Object(react["useState"])(null),_useState10=Object(slicedToArray["a" /* default */])(_useState9,2),currentScheduleWeek=_useState10[0],setCurrentScheduleWeek=_useState10[1];var _useState11=Object(react["useState"])(null),_useState12=Object(slicedToArray["a" /* default */])(_useState11,2),courses=_useState12[0],setCourses=_useState12[1];var setScheduleStates=function setScheduleStates(currentScheduleWeek){var _currentScheduleWeek$,_currentScheduleWeek$2,_currentScheduleWeek$3;setCurrentSchedule(currentScheduleWeek);setSelectedWeekId(currentScheduleWeek===null||currentScheduleWeek===void 0?void 0:(_currentScheduleWeek$=currentScheduleWeek.at(0))===null||_currentScheduleWeek$===void 0?void 0:(_currentScheduleWeek$2=_currentScheduleWeek$.id)===null||_currentScheduleWeek$2===void 0?void 0:_currentScheduleWeek$2.toString());setCurrentScheduleWeek((_currentScheduleWeek$3=currentScheduleWeek===null||currentScheduleWeek===void 0?void 0:currentScheduleWeek.at(0))!==null&&_currentScheduleWeek$3!==void 0?_currentScheduleWeek$3:null);};var getSchedule=Object(react["useCallback"])(/*#__PURE__*/Object(asyncToGenerator["a" /* default */])(/*#__PURE__*/Object(regeneratorRuntime["a" /* default */])().mark(function _callee(){var errorToRender,_props$program,scheduleResponse,_scheduleResponse;return Object(regeneratorRuntime["a" /* default */])().wrap(function _callee$(_context){while(1){switch(_context.prev=_context.next){case 0:errorToRender=null;setLoading(true);_context.prev=2;if(!(((_props$program=props.program)===null||_props$program===void 0?void 0:_props$program.type)==='cohort')){_context.next=10;break;}_context.next=6;return backendClient.getFresnelCurrentScheduleWeek(userId);case 6:scheduleResponse=_context.sent;setScheduleStates(scheduleResponse===null||scheduleResponse===void 0?void 0:scheduleResponse.currentScheduleWeek);_context.next=14;break;case 10:_context.next=12;return backendClient.getLiteCurrentScheduleWeek(userId);case 12:_scheduleResponse=_context.sent;// TODO:  Need to manage course selection here
// setScheduleStates(scheduleResponse);
setCourses(_scheduleResponse);case 14:_context.next=20;break;case 16:_context.prev=16;_context.t0=_context["catch"](2);console.log(_context.t0);errorToRender="Error retrieving schedule from Manara Backend.";case 20:setLoading(false);setError(errorToRender);case 22:case"end":return _context.stop();}}},_callee,null,[[2,16]]);})),[]);var handleDropdownSelect=function handleDropdownSelect(event){var id=event.target.value;setSelectedWeekId(id);var matchingWeek=currentSchedule===null||currentSchedule===void 0?void 0:currentSchedule.filter(function(week){return week.id===id;}).at(0);console.log("Matching week:",{matchingWeek:matchingWeek});var newWeek=matchingWeek?Object(objectSpread2["a" /* default */])({},matchingWeek):null;setCurrentScheduleWeek(newWeek);};console.log("Current schedule",{currentSchedule:currentSchedule});console.log("Current schedule week",{currentScheduleWeek:currentScheduleWeek});console.log("Selected Week Id",{selectedWeekId:selectedWeekId});Object(react["useEffect"])(function(){getSchedule();},[]);// TODO: Update No schedule week message
var dropdownTitle=function dropdownTitle(index,total){var _props$program2;if(((_props$program2=props.program)===null||_props$program2===void 0?void 0:_props$program2.type)==='cohort'){return"Week ".concat(total-index);}else{return"Module ".concat(total-index);}};if(((_props$program3=props.program)===null||_props$program3===void 0?void 0:_props$program3.type)!==ProgramType.COHORT&&courses&&!currentSchedule){return/*#__PURE__*/Object(jsx_runtime["jsx"])(CourseSelection,{courses:courses,setCourse:setScheduleStates});}return/*#__PURE__*/Object(jsx_runtime["jsxs"])(jsx_runtime["Fragment"],{children:[error&&/*#__PURE__*/Object(jsx_runtime["jsx"])(Alert["a" /* default */],{severity:"error",children:error}),loading&&/*#__PURE__*/Object(jsx_runtime["jsx"])(Grid["a" /* default */],{container:true,justifyContent:"center",alignItems:"center",children:/*#__PURE__*/Object(jsx_runtime["jsx"])(CircularProgress["a" /* default */],{})}),currentSchedule&&currentScheduleWeek&&/*#__PURE__*/Object(jsx_runtime["jsx"])(jsx_runtime["Fragment"],{children:/*#__PURE__*/Object(jsx_runtime["jsx"])(Grid["a" /* default */],{container:true,columnSpacing:1,sx:{my:"0.5rem"},children:/*#__PURE__*/Object(jsx_runtime["jsxs"])(Grid["a" /* default */],{container:true,item:true,xs:6,sx:{alignItems:"center"},children:[/*#__PURE__*/Object(jsx_runtime["jsx"])(Grid["a" /* default */],{item:true,xs:6,children:/*#__PURE__*/Object(jsx_runtime["jsx"])(FormControl["a" /* default */],{children:/*#__PURE__*/Object(jsx_runtime["jsx"])(Select["a" /* default */],{inputProps:{MenuProps:{disableScrollLock:true}},labelId:"schedule-week-select",id:"schedule-week-select",value:selectedWeekId,onChange:handleDropdownSelect,children:currentSchedule.map(function(week,index){return/*#__PURE__*/Object(jsx_runtime["jsx"])(MenuItem["a" /* default */],{selected:week.id===currentScheduleWeek.id,value:week.id,children:dropdownTitle(index,currentSchedule.length)});})})})}),/*#__PURE__*/Object(jsx_runtime["jsx"])(Grid["a" /* default */],{item:true,xs:6,children:/*#__PURE__*/Object(jsx_runtime["jsx"])("b",{children:currentScheduleWeek.title})})]})})}),currentScheduleWeek?/*#__PURE__*/Object(jsx_runtime["jsx"])(ProblemList,{backendClient:backendClient,location:location,userId:userId,selectedScheduleWeek:currentScheduleWeek,setSelectedScheduleWeek:setCurrentScheduleWeek,setError:setError,program:props.program}):!loading&&!error&&/*#__PURE__*/Object(jsx_runtime["jsxs"])(jsx_runtime["Fragment"],{children:[/*#__PURE__*/Object(jsx_runtime["jsx"])("h3",{children:"Welcome !"}),"There are currently no homework problems to get started on. But don't worry, there will be soon !"]})]});}function ProblemList(props){var location=props.location,backendClient=props.backendClient,userId=props.userId,selectedScheduleWeek=props.selectedScheduleWeek,setSelectedScheduleWeek=props.setSelectedScheduleWeek,setError=props.setError;var _useState13=Object(react["useState"])({}),_useState14=Object(slicedToArray["a" /* default */])(_useState13,2),problemLoadingStates=_useState14[0],setProblemLoadingStates=_useState14[1];var problemSlug=parseProblemSlug(location);var refreshSubmissionInfo=Object(react["useCallback"])(/*#__PURE__*/function(){var _ref2=Object(asyncToGenerator["a" /* default */])(/*#__PURE__*/Object(regeneratorRuntime["a" /* default */])().mark(function _callee2(currentSchedule,userId,problemSlug){var homeworkProblem,loadingStates,errorToRender,refreshedSubmission,_currentSchedule$prob,newScheduleWeek,doneLoadStates,_loadingStates;return Object(regeneratorRuntime["a" /* default */])().wrap(function _callee2$(_context2){while(1){switch(_context2.prev=_context2.next){case 0:if(!problemSlug){_context2.next=26;break;}homeworkProblem=currentSchedule===null||currentSchedule===void 0?void 0:currentSchedule.problems.find(function(problem){return problem.leetcodeSlug===problemSlug;});if(homeworkProblem){_context2.next=4;break;}return _context2.abrupt("return");case 4:loadingStates=Object(objectSpread2["a" /* default */])({},problemLoadingStates);loadingStates[homeworkProblem.leetcodeSlug]=true;setProblemLoadingStates(loadingStates);errorToRender=null;_context2.prev=8;_context2.next=11;return backendClient.refreshSubmissionInfo(userId,problemSlug);case 11:refreshedSubmission=_context2.sent;if(refreshedSubmission!==null&&refreshedSubmission!==void 0&&refreshedSubmission.submission){newScheduleWeek=Object(objectSpread2["a" /* default */])({},currentSchedule);newScheduleWeek.problems=((_currentSchedule$prob=currentSchedule===null||currentSchedule===void 0?void 0:currentSchedule.problems)!==null&&_currentSchedule$prob!==void 0?_currentSchedule$prob:[]).map(function(a){var problem=Object(objectSpread2["a" /* default */])({},a);if(problem.leetcodeSlug===problemSlug){if(!problem.submission){problem.submission=Object(objectSpread2["a" /* default */])({},refreshedSubmission.submission);}else{problem.submission.lastUpdatedTime=new Date();problem.submission.leetcodeSubmissionId=refreshedSubmission.submission.leetcodeSubmissionId;problem.submission.leetcodeSubmissionDateTime=refreshedSubmission.submission.leetcodeSubmissionDateTime;problem.submission.status=refreshedSubmission.submission.status;}}return problem;});setSelectedScheduleWeek(newScheduleWeek);}doneLoadStates=Object(objectSpread2["a" /* default */])({},loadingStates);doneLoadStates[homeworkProblem.leetcodeSlug]=false;setProblemLoadingStates(doneLoadStates);_context2.next=24;break;case 18:_context2.prev=18;_context2.t0=_context2["catch"](8);errorToRender="Error retrieving submission.  Please try again in a few moments.";_loadingStates=Object(objectSpread2["a" /* default */])({},problemLoadingStates);_loadingStates[homeworkProblem.leetcodeSlug]=false;setProblemLoadingStates(_loadingStates);case 24:setError(errorToRender);setTimeout(function(){return setError(null);},3000);case 26:case"end":return _context2.stop();}}},_callee2,null,[[8,18]]);}));return function(_x,_x2,_x3){return _ref2.apply(this,arguments);};}(),[]);var problems=[];if(selectedScheduleWeek){var _selectedScheduleWeek;problems=(_selectedScheduleWeek=selectedScheduleWeek.problems)!==null&&_selectedScheduleWeek!==void 0?_selectedScheduleWeek:[];}var problemsCompleted=problems.filter(function(problem){var _problem$submission;return((_problem$submission=problem.submission)===null||_problem$submission===void 0?void 0:_problem$submission.status)==="Accepted";});console.log("Problems",{problems:problems});var progressPercentage=100*problemsCompleted.length/problems.length;if(problems.length===0){return/*#__PURE__*/Object(jsx_runtime["jsxs"])(jsx_runtime["Fragment"],{children:[/*#__PURE__*/Object(jsx_runtime["jsx"])("h3",{children:"Welcome !"}),"There are currently no homework problems to get started on. But don't worry, there will be soon !"]});}if(selectedScheduleWeek!==undefined){var _props$program4;return/*#__PURE__*/Object(jsx_runtime["jsxs"])(jsx_runtime["Fragment"],{children:[((_props$program4=props.program)===null||_props$program4===void 0?void 0:_props$program4.type)===ProgramType.COHORT&&ProblemList_dates(selectedScheduleWeek),/*#__PURE__*/Object(jsx_runtime["jsx"])(LinearProgressWithLabel,{value:progressPercentage}),/*#__PURE__*/Object(jsx_runtime["jsx"])(components_Table,{problems:problems,activeProblemSlug:problemSlug,problemLoadingStates:problemLoadingStates,refreshSubmissionInfo:refreshSubmissionInfo,currentScheduleWeek:selectedScheduleWeek,userId:userId})]});}return/*#__PURE__*/Object(jsx_runtime["jsx"])(Grid["a" /* default */],{container:true,justifyContent:"center",alignItems:"center",children:/*#__PURE__*/Object(jsx_runtime["jsx"])(CircularProgress["a" /* default */],{})});}
// EXTERNAL MODULE: ./node_modules/@mui/icons-material/esm/CheckCircle.js
var CheckCircle = __webpack_require__(226);

// EXTERNAL MODULE: ./node_modules/@mui/icons-material/esm/Dangerous.js
var Dangerous = __webpack_require__(227);

// EXTERNAL MODULE: ./node_modules/@mui/material/esm/TextField/TextField.js + 7 modules
var TextField = __webpack_require__(232);

// CONCATENATED MODULE: ./src/components/Auth.tsx
var AuthProcessState;(function(AuthProcessState){AuthProcessState[AuthProcessState["NOT_STARTED"]=0]="NOT_STARTED";AuthProcessState[AuthProcessState["GETTING_LEETCODE"]=1]="GETTING_LEETCODE";AuthProcessState[AuthProcessState["GETTING_MANARA"]=2]="GETTING_MANARA";AuthProcessState[AuthProcessState["COMPLETE"]=3]="COMPLETE";})(AuthProcessState||(AuthProcessState={}));function Auth(_ref){var error=_ref.error,authProcessState=_ref.authProcessState,leetcodeAuth=_ref.leetcodeAuth,manaraAuth=_ref.manaraAuth,waitingForLogin=_ref.waitingForLogin,onLogin=_ref.onLogin;var _useState=Object(react["useState"])(""),_useState2=Object(slicedToArray["a" /* default */])(_useState,2),emailInput=_useState2[0],setEmailInput=_useState2[1];var _useState3=Object(react["useState"])(""),_useState4=Object(slicedToArray["a" /* default */])(_useState3,2),secretInput=_useState4[0],setSecretInput=_useState4[1];var handleEmailChange=function handleEmailChange(event){setEmailInput(event.target.value);};var handleSecretChange=function handleSecretChange(event){setSecretInput(event.target.value);};var isLoadingAuthStatus=authProcessState===AuthProcessState.GETTING_MANARA||authProcessState===AuthProcessState.GETTING_LEETCODE;var notLoggedWithManara=authProcessState===AuthProcessState.COMPLETE&&!manaraAuth;var notLoggedWithLeetCode=authProcessState===AuthProcessState.COMPLETE&&!leetcodeAuth;var isAuthenticatingLeetCode=authProcessState===AuthProcessState.GETTING_LEETCODE;return/*#__PURE__*/Object(jsx_runtime["jsxs"])("h2",{children:[error&&/*#__PURE__*/Object(jsx_runtime["jsx"])(Alert["a" /* default */],{severity:"error",children:error}),/*#__PURE__*/Object(jsx_runtime["jsxs"])("div",{style:{border:"solid 0.1rem lightgrey",borderRadius:"10px",padding:"1rem"},children:[/*#__PURE__*/Object(jsx_runtime["jsxs"])("div",{children:["Leetcode Authentication:"," ",isAuthenticatingLeetCode?/*#__PURE__*/Object(jsx_runtime["jsx"])(CircularProgress["a" /* default */],{size:"0.75rem"}):leetcodeAuth?/*#__PURE__*/Object(jsx_runtime["jsx"])(CheckCircle["a" /* default */],{color:"success",fontSize:"small"}):/*#__PURE__*/Object(jsx_runtime["jsx"])(Dangerous["a" /* default */],{color:"error",fontSize:"small"})]}),/*#__PURE__*/Object(jsx_runtime["jsx"])("div",{children:notLoggedWithLeetCode&&/*#__PURE__*/Object(jsx_runtime["jsxs"])(jsx_runtime["Fragment"],{children:[/*#__PURE__*/Object(jsx_runtime["jsx"])("br",{}),/*#__PURE__*/Object(jsx_runtime["jsx"])(Grid["a" /* default */],{container:true,justifyContent:"center",alignItems:"center",children:/*#__PURE__*/Object(jsx_runtime["jsx"])(Button["a" /* default */],{variant:"contained",onClick:function onClick(){return chrome.tabs.create({url:"https://leetcode.com/accounts/login/"});},children:"Login to LeetCode"})})]})})]}),/*#__PURE__*/Object(jsx_runtime["jsxs"])("div",{style:{margin:"2rem 0rem",border:"solid 0.1rem lightgrey",borderRadius:"10px",padding:"1rem"},children:[/*#__PURE__*/Object(jsx_runtime["jsxs"])("div",{children:["Manara Authentication:"," ",isLoadingAuthStatus?/*#__PURE__*/Object(jsx_runtime["jsx"])(CircularProgress["a" /* default */],{size:"0.75rem"}):manaraAuth?/*#__PURE__*/Object(jsx_runtime["jsx"])(CheckCircle["a" /* default */],{color:"success",fontSize:"small"}):/*#__PURE__*/Object(jsx_runtime["jsx"])(Dangerous["a" /* default */],{color:"error",fontSize:"small"})]}),notLoggedWithManara&&/*#__PURE__*/Object(jsx_runtime["jsx"])("div",{children:/*#__PURE__*/Object(jsx_runtime["jsxs"])(jsx_runtime["Fragment"],{children:[/*#__PURE__*/Object(jsx_runtime["jsxs"])(Grid["a" /* default */],{container:true,alignItems:"center",children:[/*#__PURE__*/Object(jsx_runtime["jsx"])(TextField["a" /* default */],{required:true,hiddenLabel:false,id:"outlined-required",label:"Email (Required)",onChange:handleEmailChange,disabled:waitingForLogin,margin:"normal"}),/*#__PURE__*/Object(jsx_runtime["jsx"])(TextField["a" /* default */],{required:true,hiddenLabel:false,id:"outlined-password-input",label:"Secret (Required)",type:"password",onChange:handleSecretChange,disabled:waitingForLogin,margin:"normal"})]}),/*#__PURE__*/Object(jsx_runtime["jsx"])(Button["a" /* default */],{color:"primary",variant:"contained",onClick:function onClick(){return onLogin(emailInput,secretInput);},disabled:waitingForLogin,children:"Login"}),waitingForLogin&&/*#__PURE__*/Object(jsx_runtime["jsx"])(CircularProgress["a" /* default */],{size:"0.75rem"})]})})]})]});};
// CONCATENATED MODULE: ./src/components/ProgramSelection.tsx
function ProgramSelection(props){function saveProgram(program){chrome.storage.local.set({program:program});props.setProgram(program);}var buttons=props.programs.map(function(program){return/*#__PURE__*/Object(jsx_runtime["jsx"])(Button["a" /* default */],{style:{margin:"1rem"},color:"primary",variant:"contained",fullWidth:true,onClick:function onClick(){return saveProgram(program);},children:program.type===ProgramType.COHORT?'Manara Cohort':'Manara Flexible'});});return/*#__PURE__*/Object(jsx_runtime["jsx"])("div",{style:{margin:"2rem 0rem",border:"solid 0.1rem lightgrey",borderRadius:"10px",padding:"1rem"},children:/*#__PURE__*/Object(jsx_runtime["jsxs"])(Grid["a" /* default */],{container:true,alignItems:"center",style:{padding:"1rem",textAlign:"center",justifyContent:"center"},children:[/*#__PURE__*/Object(jsx_runtime["jsx"])("h1",{children:"Select Program"}),buttons]})});};
// EXTERNAL MODULE: ./node_modules/@babel/runtime/helpers/esm/classCallCheck.js
var classCallCheck = __webpack_require__(68);

// EXTERNAL MODULE: ./node_modules/@babel/runtime/helpers/esm/createClass.js
var createClass = __webpack_require__(69);

// EXTERNAL MODULE: ./node_modules/axios/index.js
var axios = __webpack_require__(61);
var axios_default = /*#__PURE__*/__webpack_require__.n(axios);

// CONCATENATED MODULE: ./src/services/backend.ts
var backend_BackendClient=/*#__PURE__*/function(){function BackendClient(){Object(classCallCheck["a" /* default */])(this,BackendClient);this.accessToken=void 0;this.leetcodeAuthInfo=void 0;this.leetcodeAuthInfo=null;this.accessToken=null;}Object(createClass["a" /* default */])(BackendClient,[{key:"getLeetcodeHeaders",value:function getLeetcodeHeaders(){if(!this.leetcodeAuthInfo){throw new Error("No Leetcode Auth Info!");}return{'X-Manara-Lc-Csrf':this.leetcodeAuthInfo.csrf,'X-Manara-Lc-Session':this.leetcodeAuthInfo.session};}},{key:"getAuthorizationHeader",value:function getAuthorizationHeader(){if(!this.accessToken){throw new Error("Not authenticated with Manara Backend!");}return{'Authorization':"Bearer ".concat(this.accessToken)};}},{key:"setAccessToken",value:function setAccessToken(accessToken){this.accessToken=accessToken;}},{key:"setLeetcodeInfo",value:function setLeetcodeInfo(leetcodeAuthInfo){this.leetcodeAuthInfo=leetcodeAuthInfo;}},{key:"getFresnelCurrentScheduleWeek",value:function(){var _getFresnelCurrentScheduleWeek=Object(asyncToGenerator["a" /* default */])(/*#__PURE__*/Object(regeneratorRuntime["a" /* default */])().mark(function _callee(userId){var scheduleWeekResponse,index,newSchedule;return Object(regeneratorRuntime["a" /* default */])().wrap(function _callee$(_context){while(1){switch(_context.prev=_context.next){case 0:_context.next=2;return axios_default.a.get("".concat(BackendClient.baseUrl,"/programs/cohort/users/").concat(userId,"?ts=").concat(Date.now()),{headers:{}});case 2:scheduleWeekResponse=_context.sent.data;if(scheduleWeekResponse.currentScheduleWeek){for(index=0;index<scheduleWeekResponse.currentScheduleWeek.length;index+=1){newSchedule=scheduleWeekResponse.currentScheduleWeek[index];newSchedule.endDateTime=new Date(newSchedule.endDateTime);newSchedule.startDateTime=new Date(newSchedule.startDateTime);}scheduleWeekResponse.currentScheduleWeek.sort(function(a,b){return b.startDateTime.getTime()-a.startDateTime.getTime();});}return _context.abrupt("return",scheduleWeekResponse);case 5:case"end":return _context.stop();}}},_callee);}));function getFresnelCurrentScheduleWeek(_x){return _getFresnelCurrentScheduleWeek.apply(this,arguments);}return getFresnelCurrentScheduleWeek;}()},{key:"getLiteCurrentScheduleWeek",value:function(){var _getLiteCurrentScheduleWeek=Object(asyncToGenerator["a" /* default */])(/*#__PURE__*/Object(regeneratorRuntime["a" /* default */])().mark(function _callee2(userId){var scheduleWeekResponse,index,course,moduleIndex,newSchedule;return Object(regeneratorRuntime["a" /* default */])().wrap(function _callee2$(_context2){while(1){switch(_context2.prev=_context2.next){case 0:_context2.next=2;return axios_default.a.get("".concat(BackendClient.baseUrl,"/programs/flex/users/").concat(userId,"?ts=").concat(Date.now()),{headers:{}});case 2:scheduleWeekResponse=_context2.sent.data;if(scheduleWeekResponse.currentScheduleWeek){for(index=0;index<scheduleWeekResponse.currentScheduleWeek.length;index+=1){course=scheduleWeekResponse.currentScheduleWeek[index];for(moduleIndex=0;moduleIndex<course.modules.length;moduleIndex+=1){newSchedule=course.modules[moduleIndex];newSchedule.endDateTime=new Date(newSchedule.endDateTime);newSchedule.startDateTime=new Date(newSchedule.startDateTime);}course.modules.sort(function(a,b){return b.startDateTime.getTime()-a.startDateTime.getTime();});}}return _context2.abrupt("return",scheduleWeekResponse);case 5:case"end":return _context2.stop();}}},_callee2);}));function getLiteCurrentScheduleWeek(_x2){return _getLiteCurrentScheduleWeek.apply(this,arguments);}return getLiteCurrentScheduleWeek;}()},{key:"refreshSubmissionInfo",value:function(){var _refreshSubmissionInfo=Object(asyncToGenerator["a" /* default */])(/*#__PURE__*/Object(regeneratorRuntime["a" /* default */])().mark(function _callee3(userId,problemSlug){return Object(regeneratorRuntime["a" /* default */])().wrap(function _callee3$(_context3){while(1){switch(_context3.prev=_context3.next){case 0:if(this.accessToken){_context3.next=2;break;}throw new Error("Not authenticated!");case 2:_context3.prev=2;_context3.next=5;return axios_default.a.post("".concat(BackendClient.baseUrl,"/users/").concat(userId,"/problems/").concat(problemSlug,"/submissions"),{},{headers:Object(objectSpread2["a" /* default */])(Object(objectSpread2["a" /* default */])({},this.getAuthorizationHeader()),this.getLeetcodeHeaders())});case 5:return _context3.abrupt("return",_context3.sent.data);case 8:_context3.prev=8;_context3.t0=_context3["catch"](2);this.setLeetcodeInfo(null);_context3.next=13;return leetcodeLogout();case 13:throw new Error("Fetch submissions error!");case 14:case"end":return _context3.stop();}}},_callee3,this,[[2,8]]);}));function refreshSubmissionInfo(_x3,_x4){return _refreshSubmissionInfo.apply(this,arguments);}return refreshSubmissionInfo;}()}],[{key:"login",value:function(){var _login=Object(asyncToGenerator["a" /* default */])(/*#__PURE__*/Object(regeneratorRuntime["a" /* default */])().mark(function _callee4(email,secret){var response;return Object(regeneratorRuntime["a" /* default */])().wrap(function _callee4$(_context4){while(1){switch(_context4.prev=_context4.next){case 0:response=axios_default.a.post("".concat(BackendClient.baseUrl,"/login"),{email:email,secret:secret}).then(function(res){var _res$data;if(!(res!==null&&res!==void 0&&(_res$data=res.data)!==null&&_res$data!==void 0&&_res$data.accessToken)){throw new Error("Unexpected response during Github OAuth with Manara Backend!");}return res.data;}).catch(function(err){throw new Error("Unable to login");});return _context4.abrupt("return",response);case 2:case"end":return _context4.stop();}}},_callee4);}));function login(_x5,_x6){return _login.apply(this,arguments);}return login;}()}]);return BackendClient;}();backend_BackendClient.baseUrl="https://99y6xsjzk1.execute-api.us-east-2.amazonaws.com/prod";
// CONCATENATED MODULE: ./src/components/AppContent.tsx
/* eslint-disable react-hooks/exhaustive-deps */function AppContent(props){var _useState=Object(react["useState"])(null),_useState2=Object(slicedToArray["a" /* default */])(_useState,2),location=_useState2[0],setLocation=_useState2[1];var _useState3=Object(react["useState"])(null),_useState4=Object(slicedToArray["a" /* default */])(_useState3,2),error=_useState4[0],setError=_useState4[1];var _useState5=Object(react["useState"])(AuthProcessState.NOT_STARTED),_useState6=Object(slicedToArray["a" /* default */])(_useState5,2),authProcessState=_useState6[0],setAuthProcessState=_useState6[1];var _useState7=Object(react["useState"])(false),_useState8=Object(slicedToArray["a" /* default */])(_useState7,2),waitingForLogin=_useState8[0],setWaitingForLogin=_useState8[1];var _useState9=Object(react["useState"])(false),_useState10=Object(slicedToArray["a" /* default */])(_useState9,2),isValidLeetcodeCredentials=_useState10[0],setIsValidLeetcodeCredentials=_useState10[1];var checkAuth=Object(react["useCallback"])(/*#__PURE__*/Object(asyncToGenerator["a" /* default */])(/*#__PURE__*/Object(regeneratorRuntime["a" /* default */])().mark(function _callee2(){var _storage$manaraChrome,_props$manaraAuth,_props$manaraAuth$pro;var errorToRender,storage;return Object(regeneratorRuntime["a" /* default */])().wrap(function _callee2$(_context2){while(1){switch(_context2.prev=_context2.next){case 0:// Attempt to get leetcode information:
setAuthProcessState(AuthProcessState.GETTING_LEETCODE);_context2.t0=props;_context2.next=4;return checkLeetcodeAuth();case 4:_context2.t1=_context2.sent;_context2.t0.setLeetcodeAuth.call(_context2.t0,_context2.t1);errorToRender=null;// Check if we already have Manara Authentication Cached for the User
setAuthProcessState(AuthProcessState.GETTING_MANARA);console.log("Checking local storage for Manara Access Token...");_context2.next=11;return chrome.storage.local.get(["manaraChrome","program"]);case 11:storage=_context2.sent;if(storage!==null&&storage!==void 0&&(_storage$manaraChrome=storage.manaraChrome)!==null&&_storage$manaraChrome!==void 0&&_storage$manaraChrome.accessToken){console.log("Found Manara Chrome Access Info!");props.setManaraAuth(storage===null||storage===void 0?void 0:storage.manaraChrome);}else{console.log("No Manara Access Token found!");}if(((_props$manaraAuth=props.manaraAuth)===null||_props$manaraAuth===void 0?void 0:(_props$manaraAuth$pro=_props$manaraAuth.program)===null||_props$manaraAuth$pro===void 0?void 0:_props$manaraAuth$pro.length)===1){props.setProgram(props.manaraAuth.program[0]);}else if(storage!==null&&storage!==void 0&&storage.program){props.setProgram(storage.program);}setAuthProcessState(AuthProcessState.COMPLETE);setError(errorToRender);// TODO - extract to problem list component
chrome.tabs&&chrome.tabs.query({active:true,currentWindow:true},function(tabs){chrome.tabs.sendMessage(tabs[0].id||0,{type:"GET_WINDOW_LOCATION"},/*#__PURE__*/function(){var _ref2=Object(asyncToGenerator["a" /* default */])(/*#__PURE__*/Object(regeneratorRuntime["a" /* default */])().mark(function _callee(response){return Object(regeneratorRuntime["a" /* default */])().wrap(function _callee$(_context){while(1){switch(_context.prev=_context.next){case 0:if(!window.chrome.runtime.lastError){if(response!==null&&response!==void 0&&response.location)setLocation(response.location);}case 1:case"end":return _context.stop();}}},_callee);}));return function(_x){return _ref2.apply(this,arguments);};}());});case 17:case"end":return _context2.stop();}}},_callee2);})),[]);Object(react["useEffect"])(function(){checkAuth();},[]);var backendClient=Object(react["useMemo"])(function(){var client=new backend_BackendClient();if(props.manaraAuth){client.setAccessToken(props.manaraAuth.accessToken);}if(props.leetcodeAuth){client.setLeetcodeInfo(props.leetcodeAuth);}return client;},[props.manaraAuth,props.leetcodeAuth]);var checkAndValidateLeetcodeCredentials=/*#__PURE__*/function(){var _ref3=Object(asyncToGenerator["a" /* default */])(/*#__PURE__*/Object(regeneratorRuntime["a" /* default */])().mark(function _callee3(){return Object(regeneratorRuntime["a" /* default */])().wrap(function _callee3$(_context3){while(1){switch(_context3.prev=_context3.next){case 0:_context3.prev=0;console.log('Validating Leetcode credentials...');if(!(props.manaraAuth&&props.leetcodeAuth)){_context3.next=6;break;}_context3.next=5;return backendClient.refreshSubmissionInfo(props.manaraAuth.id,'check-if-two-string-arrays-are-equivalent');case 5:setIsValidLeetcodeCredentials(true);case 6:_context3.next=14;break;case 8:_context3.prev=8;_context3.t0=_context3["catch"](0);console.log('Leetcode credentials validation error:',_context3.t0);setError('Failed to validate Leetcode credentials');props.setLeetcodeAuth(null);setIsValidLeetcodeCredentials(false);case 14:case"end":return _context3.stop();}}},_callee3,null,[[0,8]]);}));return function checkAndValidateLeetcodeCredentials(){return _ref3.apply(this,arguments);};}();Object(react["useEffect"])(function(){checkAndValidateLeetcodeCredentials();},[props.manaraAuth,props.leetcodeAuth]);var handleLogin=Object(react["useCallback"])(/*#__PURE__*/function(){var _ref4=Object(asyncToGenerator["a" /* default */])(/*#__PURE__*/Object(regeneratorRuntime["a" /* default */])().mark(function _callee4(email,secret){var manaraAuthResponse;return Object(regeneratorRuntime["a" /* default */])().wrap(function _callee4$(_context4){while(1){switch(_context4.prev=_context4.next){case 0:_context4.prev=0;setWaitingForLogin(true);setError(null);_context4.next=5;return backend_BackendClient.login(email,secret);case 5:manaraAuthResponse=_context4.sent;if(manaraAuthResponse){chrome.storage.local.set({manaraChrome:manaraAuthResponse});props.setManaraAuth(manaraAuthResponse);}_context4.next=13;break;case 9:_context4.prev=9;_context4.t0=_context4["catch"](0);console.log(_context4.t0);setError("Error logging in!");case 13:setWaitingForLogin(false);case 14:case"end":return _context4.stop();}}},_callee4,null,[[0,9]]);}));return function(_x2,_x3){return _ref4.apply(this,arguments);};}(),[]);if(props.manaraAuth&&props.leetcodeAuth&&isValidLeetcodeCredentials){var _props$manaraAuth$pro2;if(props.program){return/*#__PURE__*/Object(jsx_runtime["jsx"])(ProblemListPage,{backendClient:backendClient,location:location,userId:props.manaraAuth.id,program:props.program});}else if(((_props$manaraAuth$pro2=props.manaraAuth.program)===null||_props$manaraAuth$pro2===void 0?void 0:_props$manaraAuth$pro2.length)>0){return/*#__PURE__*/Object(jsx_runtime["jsx"])(ProgramSelection,{programs:props.manaraAuth.program,setProgram:props.setProgram});}else{return/*#__PURE__*/Object(jsx_runtime["jsx"])("div",{children:"You aren't currently enrolled in any Manara programs which use this extension."});}}return/*#__PURE__*/Object(jsx_runtime["jsx"])(Auth,{error:error,manaraAuth:props.manaraAuth,leetcodeAuth:props.leetcodeAuth,authProcessState:authProcessState,waitingForLogin:waitingForLogin,onLogin:handleLogin});};
// EXTERNAL MODULE: ./node_modules/@mui/icons-material/Close.js
var Close = __webpack_require__(110);
var Close_default = /*#__PURE__*/__webpack_require__.n(Close);

// EXTERNAL MODULE: ./src/App.css
var App = __webpack_require__(166);

// CONCATENATED MODULE: ./src/App.tsx
/* eslint-disable react-hooks/exhaustive-deps */function App_App(){var _manaraAuth$program;var _useState=Object(react["useState"])(null),_useState2=Object(slicedToArray["a" /* default */])(_useState,2),leetcodeAuth=_useState2[0],setLeetcodeAuth=_useState2[1];var _useState3=Object(react["useState"])(null),_useState4=Object(slicedToArray["a" /* default */])(_useState3,2),manaraAuth=_useState4[0],setManaraAuth=_useState4[1];var _useState5=Object(react["useState"])(null),_useState6=Object(slicedToArray["a" /* default */])(_useState5,2),program=_useState6[0],setProgram=_useState6[1];var _useState7=Object(react["useState"])(null),_useState8=Object(slicedToArray["a" /* default */])(_useState7,2),course=_useState8[0],setCourse=_useState8[1];return/*#__PURE__*/Object(jsx_runtime["jsxs"])(jsx_runtime["Fragment"],{children:[/*#__PURE__*/Object(jsx_runtime["jsx"])(Box["a" /* default */],{sx:{p:4,flexGrow:1},children:/*#__PURE__*/Object(jsx_runtime["jsxs"])(Grid["a" /* default */],{container:true,justifyContent:"center",spacing:2,children:[/*#__PURE__*/Object(jsx_runtime["jsxs"])(Grid["a" /* default */],{item:true,container:true,xs:12,justifyContent:"center",alignContent:"center",children:[/*#__PURE__*/Object(jsx_runtime["jsx"])("img",{src:"/images/manara-logo-black-text.svg",alt:"Manara logo"}),leetcodeAuth&&manaraAuth&&program&&/*#__PURE__*/Object(jsx_runtime["jsxs"])("p",{children:["\xA0: ",program.label]}),manaraAuth&&((_manaraAuth$program=manaraAuth.program)===null||_manaraAuth$program===void 0?void 0:_manaraAuth$program.length)>=1&&program&&/*#__PURE__*/Object(jsx_runtime["jsx"])(Button["a" /* default */],{onClick:function onClick(){setProgram(null);},children:/*#__PURE__*/Object(jsx_runtime["jsx"])(Close_default.a,{sx:{position:"fixed",top:"0.5rem",right:"0.5rem",zIndex:2000,backgroundColor:"lightgray"}})})]}),/*#__PURE__*/Object(jsx_runtime["jsx"])(Grid["a" /* default */],{item:true,xs:12,children:/*#__PURE__*/Object(jsx_runtime["jsx"])(AppContent,{manaraAuth:manaraAuth,program:program,course:course,setManaraAuth:setManaraAuth,setProgram:setProgram,setCourse:setCourse,leetcodeAuth:leetcodeAuth,setLeetcodeAuth:setLeetcodeAuth})})]})}),/*#__PURE__*/Object(jsx_runtime["jsx"])("div",{className:"version",children:"v.".concat(VERSION)})]});}/* harmony default export */ var src_App = (App_App);
// CONCATENATED MODULE: ./src/reportWebVitals.ts
var reportWebVitals=function reportWebVitals(onPerfEntry){if(onPerfEntry&&onPerfEntry instanceof Function){__webpack_require__.e(/* import() */ 3).then(__webpack_require__.bind(null, 254)).then(function(_ref){var getCLS=_ref.getCLS,getFID=_ref.getFID,getFCP=_ref.getFCP,getLCP=_ref.getLCP,getTTFB=_ref.getTTFB;getCLS(onPerfEntry);getFID(onPerfEntry);getFCP(onPerfEntry);getLCP(onPerfEntry);getTTFB(onPerfEntry);});}};/* harmony default export */ var src_reportWebVitals = (reportWebVitals);
// CONCATENATED MODULE: ./src/index.tsx
react_dom_default.a.render(/*#__PURE__*/Object(jsx_runtime["jsx"])(react_default.a.StrictMode,{children:/*#__PURE__*/Object(jsx_runtime["jsx"])(src_App,{})}),document.getElementById('root'));// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
src_reportWebVitals();

/***/ })

/******/ });
//# sourceMappingURL=main.js.map