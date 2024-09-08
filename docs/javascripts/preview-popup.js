// @ts-check

const NOTICE_ELEMENT_ID = "git-preview-notice";

function hidePreviewNotice() {
    const el = document.getElementById(NOTICE_ELEMENT_ID);
    if (el != null) {
        el.hidden = true;
    }
    sessionStorage.setItem("gitPreviewNoticeHidden", "yes");
}

const regex = /^\/?commit\/([0-9a-f]{7,8})\/.*$/;
if (
    sessionStorage.getItem("gitPreviewNoticeHidden") !== "yes" &&
    regex.test(window.location.pathname)
) {
    const regexResult = window.location.pathname.match(regex);
    let commitHash = "???";
    if (regexResult != null) {
        commitHash = regexResult[1] ?? "???";
    }
    document.body.insertAdjacentHTML(
        "afterbegin",
        /*html*/ `
            <div style="bottom: 0;top: unset;position: fixed;z-index: 999;border-radius: 10px;padding: 20px;max-width: 100%;text-align: center;"
                class="md-typeset md-banner" id="${NOTICE_ELEMENT_ID}">
                <div style="font-size: 1.5em;">Ta strona została wygenerowana automatycznie przez commit <b>${commitHash}</b></div>
                <a href="javascript:hidePreviewNotice();" class="md-button md-button--primary" style="background-color: var(--md-admonition-bg-color);border-color: var(--md-admonition-bg-color);margin: 6px;color:var(--md-admonition-fg-color);">
                    Rozumiem
                </a>
                <a href="https://kursy.szkopul.edu.pl" class="md-button md-button--primary" style="margin: 6px;">
                    Przejdź do kursów oficjalnych
                </a>
            </div>
        `
    );
}
