<?
/**
 * @name         lib XAJAX
 * @version      1.0
 * @package      framework
 * @author       J P Fonseka <jo@respere.com>
 * @author       Greg Miernicki <g@miernicki.com> <gregory.miernicki@nih.gov>
 * @about        Developed in whole or part by the U.S. National Library of Medicine
 * @link         https://pl.nlm.nih.gov/about
 * @link         http://sahanafoundation.org
 * @license	 http://www.gnu.org/licenses/lgpl-2.1.html GNU Lesser General Public License (LGPL)
 * @lastModified 2011.0308
 */


require_once($global['approot']."/3rd/xajax/xajax.inc.php");

//set the xajx object which developer should use in there code
global $global;
$global['xajax'] = new xajax('index.php?stream=ajax&mod=xst&act=xajax','');

/**
 * these functions are just to make it convienent for the developers
 */
function shn_xajax_registerFunction($name){
	global $global;
	$global['xajax']->registerFunction($name);
}



/**
 * print javascript function this will be called in html stream library if xajax
 * object exist in global variable
 */
function shn_xajax_printJavascript(){
	global $global;
	// allow user to call this function
	// but overall it will be called only once per execution because of the static variable
	static $i;
	if($i==0 || $i==null){
		$i=0;
		//set the default uri
		$sRequestURI='index.php?stream=ajax&mod=xst&act=xajax';
		$global['xajax']->setRequestURI($sRequestURI);
		$global['xajax']->printJavascript("res/js");
		//java script to xajax loading message
		?>
<script type="text/javascript">
<!--
            xajax.loadingFunction =
                function(){xajax.$('loadingMessage').style.display='block';alert('start');};
            function hideLoadingMessage()
            {
                xajax.$('loadingMessage').style.display = 'none';alert('stop');
            }
            xajax.doneLoadingFunction = hideLoadingMessage;
// --></script>
<div id="loadingMessage" style="display: none;">Loading...</div>
		<?php
		$i++;
	}
}
