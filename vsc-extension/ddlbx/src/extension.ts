import * as vscode from 'vscode';

export function activate(context: vscode.ExtensionContext) {
    // Register a language provider
    const ddlbxLanguageProvider = vscode.languages.registerCompletionItemProvider('DDLBX', {
        provideCompletionItems(document: vscode.TextDocument, position: vscode.Position) {
            // Implement your completion logic here
            const completionItem = new vscode.CompletionItem('HelloWorld');
            return [completionItem];
        }
    });

    context.subscriptions.push(ddlbxLanguageProvider);

    // Add status bar item
    const statusBarItem = vscode.window.createStatusBarItem(vscode.StatusBarAlignment.Right, 100);
    statusBarItem.text = '$(globe) ddlbx';
    statusBarItem.tooltip = 'Select Language Mode';
    statusBarItem.command = 'workbench.action.editor.changeLanguageMode';
    context.subscriptions.push(statusBarItem);

    // Show the status bar item
    statusBarItem.show();
}
